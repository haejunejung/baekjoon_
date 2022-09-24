#include <iostream>

using namespace std;

int N; /* 이닝(회) */
int player[51][10]; /* 각 회마다 선수들이 어떻게 치는지 input */
bool check[10]; /* 각 선수 정해졌는지 */
int battiming[10]; /* 몇 번째 타석에 어떤 선수가 배치 되었는지, */
int res; /* 점수 */
int runner[5];

void input ()
{
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cin >> player[i][j];
        }
    }
}

void playbaseball (int n, int BatNumCount, int Score, int outCount)
{
    if (n == N+1) /* 종료 조건 (모든 회가 종료 되었을 때) */
    {
        res = max (res, Score);
        return;
    }
    else
    {
        if (BatNumCount == 10) /* 10번째 타석은 1번째 타석으로 옮겨진다. */
        {
            playbaseball(n, 1, Score, outCount);
        }

        if (outCount == 3)
        {
            for (int i = 1; i <= 3; ++i)
            {
                runner[i] = 0;
            }
            playbaseball(n+1, BatNumCount, Score, 0);
        }

        if (player[n][battiming[BatNumCount]] == 0) /* 선수가 아웃을 당했다면, */
        {
            if (outCount == 2) 
            {
                for (int i = 1; i <= 3; ++i) /* 주자 초기화 */
                {
                    runner[i] = 0;
                }
                playbaseball(n+1, BatNumCount+1, Score, 0);
            }
            playbaseball(n, BatNumCount+1, Score, outCount+1);
        }
        
        int frontNum = player[n][battiming[BatNumCount]];
        for (int i = 3; i >= 1; --i)
        {
            if (runner[i])
            {
                runner[i] += frontNum; /* 모든 주자가 앞으로 진루 */
                if (runner[i] >= 4) /* 홈인 이라면, 점수 늘리고 주자 초기화 */
                {
                    Score++;
                    runner[i] = 0;
                }
            }
        }

        if (frontNum == 4) /* 홈런을 쳤다면, score + 1 후 진행, */
        {
            playbaseball(n, BatNumCount+1, Score+1, outCount);
        }

        runner[frontNum] = frontNum; /* 공을 친 선수가 앞으로 진루 */ 
        playbaseball(n, BatNumCount+1, Score, outCount); /* 다음 타석으로 이동 */   
    }

}

void SelectPlayer (int CntSelectNum) /* 각 선수가 몇 번째에 치는지 정해주는 함수 */
{
    if (CntSelectNum == 9) /* 각 선수들이 몇 번째 타석에 서는지 모두 알 경우, */
    {
        for (int i = 1; i <= 3; ++i) /* 주자들 초기화 */
        {
            runner[i] = 0;
        }
        playbaseball (1, 1, 0, 0); /* 1회, 1번째 타석, 0점, 아웃카운트 0으로 시작 */
        return;
    }

    for (int i = 1; i <= 9; ++i) /* DFS */
    {
        if (!check[i]) /* i번째 선수가 언제 치는지 모른다면, */
        {
            for (int j = 1; j <= 9; ++j)
            {
                if (!battiming[j]) /* 해당 타석이 비었다면, */
                {
                    check[i] = true;
                    battiming[j] = i; /* 해당 타석에 몇 번째 선수가 치기로 함. */

                    SelectPlayer (CntSelectNum+1);

                    check[i] = false;
                    battiming[j] = 0; /* 초기화 시켜준 후, 다른 타석에도 서도록 함 */
                }
            }
        }
    }

}

void solution ()
{
    SelectPlayer(0);

    cout << res;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input ();
    solution ();
    return 0;
}