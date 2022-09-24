#include <iostream>

int matrix[500][2];
unsigned long long dp[500][500];

int main (void) 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i][0] >> matrix[i][1]; /* 행렬의 크기 r과 c 저장 */
    }

    for (int i = 1; i < N; ++i) /* 총 돌려야 하는 반복문의 수 (0->1 0->2 ... 0->N-1) */
    {
        for (int j = 0; i+j < N; ++j) /* j는 시작 지점 i+j는 끝나는 지점 */
        {
            dp[j][i+j] = INT64_MAX; /* 처음에는 가장 큰 수로 시작 */
            for (int k = j; k <= i+j; ++k) /* jxk 와 (k+1)x(i+j)의 크기 + 두 개를 곱하였을 떄 나오는 크기 */
            {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
            }
        }
    }

    cout << dp[0][N-1]; /* 최종적으로 필요한 곱셈 연산의 최솟값 출력 */
    return 0;
}