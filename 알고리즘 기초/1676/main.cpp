#include <iostream>

int main () 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* 5가 들어가는 개수 -> 0의 개수 */

    int N;
    cin >> N;

    int count = 0;
    for (int i = 5; i <= N; i+=5) /* 5가 몇 개 있는지 확인하기 위해 5씩 더해가면서 개수 찾기 */
    {
        int temp = i;
        while (true) /* 5의 제곱수들이 있으므로 그 개수까지 파악 */
        {
            if (temp % 5 == 0) 
            {
                temp /= 5;
                count++;
            }
            else
            {
                break;
            }
        }
    }

    cout << count; /* 5가 들어있는 수 -> 0의 개수 */
    return 0;
}