#include <iostream>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool PrimeNum[1000001]; /* 소수인지 확인하는 배열 */
    fill_n(PrimeNum, 1000000, true);

    PrimeNum[0] = false;
    PrimeNum[1] = false;

    for (int i = 3; i < 1000001; i+=2) /* 홀수만 구할 경우 속도 up ? -> 시간은 똑같더라 */
    {
        if (PrimeNum[i])
        {
            for (int j = i+i; j < 1000001; j+=i)
            {
                PrimeNum[j] = false;
            }
        }
    }

    while (true)
    {
        int n;
        cin >> n;

        bool flag = false; /* 소수의 합으로 구할 수 있는지 판별 */

        if (n == 0) /* 0일 때 종료 */
            break;

        for (int i = 3; i <= n; i+=2)
        {
            if (PrimeNum[i] && PrimeNum[n-i]) /* i + n - i = n 이므로 i 와 n-i 모두 소수인 경우 출력 후 종료 */
            {
                cout << n << " = " << i << " + " << n-i << '\n';
                flag = true;
                break;
            }
        }

        if (!flag) /* flag에 의해서 소수의 합으로 만들 수 없는 경우 */
            cout << "Goldbach's conjecture is wrong" << '\n';
    }

    return 0;
}