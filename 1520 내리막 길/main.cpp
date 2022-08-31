#include <iostream>
#include <cstring>

int map[500][500] = { }; /* 각 지점의 높이를 저장하는 map */
int dp[500][500] = { }; /* 각 지점을 갈 수 있는 경로의 수 */
int dx[4] = { 0, 0, -1, 1}; /* 상하좌우 이웃한 곳 */
int dy[4] = { -1, 1, 0, 0};
int M,N;

int dfs (int height, int width)
{
    if (dp[height][width] != -1) return dp[height][width]; /* 이미 체크했던 지점 */
    if (height == 0 && width == 0) return 1; /* base case */
    else if (height < 0 || height >= M || width < 0 || width >= N) return 0; /* heap overflow */

    dp[height][width] = 0; /* 0으로 체크 되면, 한 번 체크한 지점이 된다 */
    for (int k = 0; k < 4; ++k)
    {
        int a = height + dy[k];
        int b = width + dx[k];

        if (a < 0 || a >= M || b < 0 || b >= N) continue;
        if (map[a][b] > map[height][width]) /* 현재 지점보다 높이가 높은 지점이 있다면 (0,0)에서 지나온 길이 될 수 있다 */
        {
            dp[height][width] += dfs(a,b);
        }
    }

    return dp[height][width]; /* dfs를 마치고 정상적인 return */
}

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N; /* 세로의 크기 M, 가로의 크기 N */

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j]; /* 각 높이 지정 */
        }
    }

    memset(dp, -1, sizeof(dp)); /* 한 번도 체크하지 않았다는 것을 알려주기 위해 -1로 시작 */

    cout << dfs(M-1, N-1);
    return 0; /* 정상적으로 종료 */
}