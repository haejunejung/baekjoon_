#include <iostream>

using namespace std;

int N; /* 몇 회 진행할 것인지, */
int playerBat[51][10]; /* 선수가 몇 루타를 칠 것인지, */
bool check[10]; /* 9명의 선수들이 모두 몇 번 타자인지 골라졌는지, */
int batOrder[10]; /* 9명의 선수들이 몇 번째 타자인지, */
int answer; /* 최종 정답, */


void Input ()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cin >> playerBat[i][j];
        }
    }
}

void PlayTheGame ()
{
    int score = 0; /* 점수 */
    int startPlayer = 1; /* 몇 번째 타자가 시작 선수인지 */
    bool Base[4]; /* 해당 베이스에 있는지, 없는지 */

    for (int i = 1; i <= N; ++i)
    {
        int outCount = 0; /* outCount check! */
        bool IsEndIning = false;  /* Is Ining end or not */
        for (int j = 1; j <= 3; ++j)
            Base[j] = false; /* 주자 초기화 (이닝이 시작할 때마다) */

        while (1)
        {
            for (int k = startPlayer; k <= 9; ++k) /* 이번 회의 첫 타자 -> startplayer, 9번타자까지 치고 outcount가 3이 안되면 1로 넘어간다 */
            {
                int goNext = playerBat[i][batOrder[k]]; /* 몇루타를 쳤는가, */

                if (goNext == 0) /* 아웃 */
                {
                    outCount++;
                }
                else if (goNext == 4) /* 홈런 */
                {
                    for (int l = 3; l >= 1; l--)
                    {
                        if (Base[l]) /* 모든 주자 불러오기 */
                        {
                            Base[l] = false;
                            score++;
                        }
                    }
                    score++;
                }
                else
                {
                    for (int l = 3; l >= 1; l--)
                    {
                        if (Base[l])
                        {
                            if (l + goNext >= 4) /* 주자가 홈인 */
                            {
                                score++;
                                Base[l] = false;
                            }
                            else /* 주자들이 진루 */
                            {
                                Base[l+goNext] = true;
                                Base[l] = false;
                            }
                        }
                    }
                    Base[goNext] = true; /* 타자도 진루 */
                }

                if (outCount == 3)
                {
                    if (startPlayer == 9) startPlayer = 1; /* 9번 타자에서 아웃되었을 때, 다음 이닝은 1번 타자부터 시작 */
                    else startPlayer = k + 1; /* 9번 타자가 아니라면 다음 타자가 다음 이닝 시작 타자 */
                    IsEndIning = true; /* outcount가 3이면 다음 이닝으로 넘어감 */
                    break;
                }
            }

            if (IsEndIning) break; /* 이번 회가 끝났는가? */
            startPlayer = 1; /* 9번 타자까지 outcount가 3이 안되면, 1번 타자부터 다시 시작 */
        }
    }

    answer = max(answer, score); /* 기존보다 높은 점수를 얻었다면 최신화 해주기 */
    return;
}

void DFS (int cntPlayer) /* 선수들이 몇 번 타자인지 정해주기 */
{
    if (cntPlayer == 10) /* 9명의 타자가 모두 골라졌다면, */
    {
        PlayTheGame (); /* 야구 시작 */
        return;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (!check[i])
        {
            check[i] = true; /* 해당 타자를 골랐을 경우, */
            batOrder[i] = cntPlayer; /* batOrder에 몇 번째 선수를 타자로 놓았는지, */
            DFS(cntPlayer+1);
            check[i] = false; /* 다른 순서로 (순열) 하기 위해서 안골랐다고 가정, */
            batOrder[i] = 0; /* batOrder에 선수 초기화 */
        }
    }
}

void Solution ()
{
    check[4] = true; /* 4번 타자는 이미 정해져 있다 */
    batOrder[4] = 1;
    DFS (2); /* 2번째 선수부터 몇 번 타자인지 알려주기 */

    cout << answer; /* 최종 정답 ! */
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();

    return 0; /* 올바르게 종료하였다면, return 0 */
}