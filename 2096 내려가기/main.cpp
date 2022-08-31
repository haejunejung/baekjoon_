#include <iostream>

#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

int map[100001][3]; /* 점수를 저장할 장소 (편의를 위해서 100001로 했지만 3개만으로도 구현 가능) */
int minDp[2][3]; /* 최소 점수를 나타내기 위해서 이전 단계와 현재 단계를 나타낼 수 있도록 함 */
int maxDp[2][3]; /* 최대 점수를 나타내기 위해서 이전 단계와 현재 단계를 나타낼 수 있도록 함 */
int N;

int maxScore ()
{
    maxDp[0][0] = map[0][0]; /* 첫 번째 줄은 기존 점수와 같다 */
    maxDp[0][1] = map[0][1];
    maxDp[0][2] = map[0][2];

    for (int i = 1; i < N; ++i)
    {
        /* 이전 단계의 가장 큰 점수 + 현재 위치의 점수 */
        maxDp[1][0] = map[i][0] + std::max(maxDp[0][0], maxDp[0][1]); 
        maxDp[1][1] = map[i][1] + std::max(maxDp[0][0], std::max(maxDp[0][1], maxDp[0][2]));
        maxDp[1][2] = map[i][2] + std::max(maxDp[0][1], maxDp[0][2]);

        /* 이전 단계에 있던 것을 현재 단계로 옮기고 다음 단계로 이동 */
        maxDp[0][0] = maxDp[1][0];
        maxDp[0][1] = maxDp[1][1];
        maxDp[0][2] = maxDp[1][2];
    }

    return std::max(maxDp[0][0], std::max(maxDp[0][1], maxDp[0][2]));
}

int minScore ()
{
    minDp[0][0] = map[0][0]; /* 첫 번째 줄은 기존 점수와 같다 */
    minDp[0][1] = map[0][1];
    minDp[0][2] = map[0][2];

    for (int i = 1; i < N; ++i)
    {
        /* 이전 단계의 가장 작은 점수 + 현재 위치의 점수 */
        minDp[1][0] = map[i][0] + std::min(minDp[0][0], minDp[0][1]);
        minDp[1][1] = map[i][1] + std::min(minDp[0][0], std::min(minDp[0][1], minDp[0][2]));
        minDp[1][2] = map[i][2] + std::min(minDp[0][1], minDp[0][2]);

        /* 이전 단계에 있던 것을 현재 단계로 옮기고 다음 단계로 이동 */
        minDp[0][0] = minDp[1][0];
        minDp[0][1] = minDp[1][1];
        minDp[0][2] = minDp[1][2];
    }

    return std::min(minDp[0][0], std::min(minDp[0][1], minDp[0][2]));
}

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> map[i][j];
        }
    }

    cout << maxScore() << " " << minScore();
    return 0;
}