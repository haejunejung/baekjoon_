/* 
    2022.09.24
    1. 한 지역구를 만든 후, 나머지 구역을 다른 지역구로 배정
    2. 두 지역구 모두 각 지역구끼리 연결되어 있는지 확인
    3. 모두 연결되어 있다면, 두 지역구 사이의 인구수 최솟값 확인
    4. 최종 최솟값을 구하기
    5. 최솟값이 MAX일 경우 -1 출력 (지역구끼리 모두 연결되어 있으나 모든 구역이 어느 한 지역구 안에 들어가지 않을 경우)

    1차시도 -> 왜 틀렸는지는 모르겠으나, 테스트케이스는 다 맞고 반례에서 틀림
                아마, 모두 연결되어 있는지 확인하는 함수 혹은 두 지역구를 만들 때 어떤 문제가 생기지 않았을까 생각이 듦

    조금 더, 한 번에 확실하게 풀 수 있도록 로직을 짜고 풀어야 할 것 같음 ! ! !
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* 각 지역이 어느 곳에도 속하지 않았다면 -> none, A 지역구에 속한다면 blue, B지역구에 속한다면 red로 표시 */
#define none 0
#define blue 1
#define red 2
#define MAX 987654321

int N; /* 구역 수 */
int diff; /* 인구 차이의 최솟값 (두 선거구를 나누었을 때) */
int res; /* 인구 차이의 최솟값 (최종) */
int person[11]; /* 각 지역의 인구 수 */
vector <int> connection[11]; /* 구역끼리 연결 되어있는 것을 나타내기 위한 vector */
vector <int> A; /* A 지역구의 구역 */
vector <int> B; /* B 지역구의 구역 */
bool check[11];


void Input ()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)   
        cin >> person[i];
    
    for (int i = 1; i <= N; ++i)
    {
        int connectionNum;
        cin >> connectionNum;

        for (int j = 1; j <= connectionNum; ++j)
        {
            int num;
            cin >> num;

            connection[i].push_back(num);
        }
    }

    res = MAX;
}

bool CheckAllConect ()
{
    bool IsAllconnect[11] = { };
    int sumA = 0, sumB = 0;

    IsAllconnect[A[0]] = true;
    for (int i = 0; i < A.size()-1; ++i)
    {
        for (int j = i+1; j < A.size(); ++j)
        {
            if (IsAllconnect[A[j]]) continue;
            for (int k = 0; k < connection[A[i]].size(); ++k)
            {
                if (connection[A[i]][k] == A[j])
                {
                    IsAllconnect[A[j]] = true;
                    break;
                }
            }
        }
    }

    IsAllconnect[B[0]] = true;
    for (int i = 0; i < B.size(); ++i)
    {
        for (int j = i+1; j < B.size(); ++j)
        {
            if (IsAllconnect[B[j]]) continue;
            for (int k = 0; k < connection[B[i]].size(); ++k)
            {
                if (connection[B[i]][k] == B[j])
                {
                    IsAllconnect[B[j]] = true;
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (!IsAllconnect[i]) return false;
    }

    for (int i = 0; i < A.size(); ++i)
    {
        sumA += person[A[i]];
    }

    for (int i = 0; i < B.size(); ++i)
    {
        sumB += person[B[i]];
    }

    diff = abs(sumA - sumB);
    return true;
}

void MakeAB (int pos, int count)
{
    if (pos == count)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (!check[i]) 
            {
                check[i] = true;
                B.push_back(i);
            }
        }

        if (CheckAllConect())
        {
            res = min (res, diff);
        }

        while (!B.empty())
        {
            check[B.back()] = false;
            B.pop_back();
        }

        return;
    }

    for (int i = 1; i <= N/2; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            A.push_back(i);
            MakeAB(pos+1, count);
            A.pop_back();
            check[i] = false;
        }
    }
}

void Solution ()
{
    for (int i = 1; i <= N; ++i)
    {
        MakeAB (0, i);
    }

    if (res == MAX) cout << -1;
    else cout << res;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();

    return 0;
}