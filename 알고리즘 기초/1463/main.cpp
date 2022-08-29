#include <iostream>

#define MAX 1000001
#define MIN(a,b) a < b ? a : b

int main (void) 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = new int[N+1]; /* bottom - up */
    arr[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        if (i == 2 || i == 3) /* 처음에 고정해야 하는 값 위에서 고정하지 않은 이유는 N이 3보다 작을 경우 heap overflow */
        {
            arr[i] = 1;
            continue;
        }

        int minimum = MAX; /* 처음에 최대치인 10^6으로 고정 */
        if (i % 3 == 0)
        {
            minimum = arr[i/3] + 1; /* 3으로 나누어지는 경우 */
        }

        if (i % 2 == 0)
        {
            minimum = MIN(minimum, arr[i/2] + 1); /* 2로 나누어지는 경우 */
        }

        minimum = MIN(minimum, arr[i-1] + 1); /* 위의 값과 1뺀 값과의 최소치 */

        arr[i] = minimum; /* 값 고정 (Dynamic Programming) */
    }

    cout << arr[N]; /* 최소치 출력 */
    return 0;
}