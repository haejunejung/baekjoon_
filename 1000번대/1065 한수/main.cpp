#include <iostream>

using namespace std;
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (i < 100)
        {
            count++;
            continue;
        }
        
        int num = i; /* copy num */

        int prevNum = num % 10; /* 일의 자리 */
        num /= 10;
        int nextNum = num % 10; /* 십의 자리 */
        num /= 10;

        int difference = prevNum - nextNum; /* 일의 자리와 십의 자리의 차 */

        bool flag = false; /* 등차수열을 이루는지 확인하기 위해서 flag 설정 */

        while (1)
        {
            if (num <= 0) break; /* 모든 경우를 돌렸을 경우 (등차수열일때) */

            prevNum = nextNum; /* 일의 자리 수 -> 십의 자리 수 (자릿수를 늘려가는 방식) */
            nextNum = num % 10; /* 십의 자리 수 -> 백의 자리 수 (자릿수를 늘려가는 방식) */
            num /= 10; 

            if (prevNum - nextNum != difference) /* 등차를 이루지 않는다면, */
            {
                flag = true; /* 등차가 아니다. */
                break;
            }
        }

        if (!flag) count++; /* 위 반복문을 벗어낫으므로 등차수열이다. */
        
    }

    cout << count;
    return 0;

}