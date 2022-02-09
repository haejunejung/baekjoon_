#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int digit = to_string(N).length(); // 자릿수 구하는 방식.. 
    int num = 9;

    unsigned long long cnt = 0;
    for (int i = 1; i < digit; ++i) {
        cnt += num * i;
        num *= 10;
    }

    cnt += (N - (num/9) + 1) * digit;
    cout << cnt;
    return 0;
}