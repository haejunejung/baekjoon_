/* 73%에서 오답이 나왔는데 이런 방법으로도 풀 수 있지 않을까 싶다... 나중에 고민해보면 좋을 것 같다*/
#include <iostream>

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MAP[502][502] = { }, route[502][502] = { };
    int M, N;
    cin >> M >> N;

    route[1][1] = 1;

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (MAP[i][j] < MAP[i+dx[k]][j+dy[k]])
                {
                    route[i][j] += route[i+dx[k]][j+dy[k]];
                }
            }
        }
    }

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int sum = 0;
            bool flag = false;
            for (int k = 0; k < 4; ++k)
            {
                if (MAP[i][j] < MAP[i+dx[k]][j+dy[k]])
                {
                    sum += route[i+dx[k]][j+dy[k]];
                    flag = true;
                }
            }

            if (sum != route[i][j] && flag)
                route[i][j] = sum;
        }
    }

    cout << route[M][N];

    return 0;
}