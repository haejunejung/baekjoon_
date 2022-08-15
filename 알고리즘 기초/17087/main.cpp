#include <iostream>

unsigned long long GCD (unsigned long long x, unsigned long long y)
{
    if (x%y == 0) return y;
    else return GCD (y, x%y);
}

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* 
        unsinged long long을 쓴 이유는 10^9가 있어서 오류가 뜨지 않게 하기 위함
        하지만, S를 제외한 부분에 int를 넣어도 되지 않을까 생각함 (실제로 해보지는 않았음)
    */

    unsigned long long N,S,i;
    cin >> N >> S;

    unsigned long long *input = new unsigned long long[N];
    for (i=0; i<N; ++i)
    {
        /* 핵심 => 동생의 위치와 수빈의 현재 위치의 차들의 최대 공약수가 가능한 D의 최댓값 */
        cin >> input[i];
        if (S > input[i]) input[i] = S - input[i];
        else input[i] = input[i] - S;
    }

    if (N==1) /* 동생이 한 명이면 D값이 하나로 정해져있다*/
    {
        cout << input[0] << "\n";
        return 0; /* 동생이 한 명이면 출력 후 종료 */
    }

    unsigned long long CommonDivisor = GCD (input[0], input[1]); /* 최대공약수 */
    for (i=2; i<N; ++i)
    {
        CommonDivisor = GCD (CommonDivisor, input[i]); /* 최대공약수를 계속 갱신 */
    }

    cout << CommonDivisor << "\n"; /* 가능한 D의 최댓값 출력 */
    return 0; /* 올바르게 종료 */
}