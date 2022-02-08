#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    int num;
    stack <int> stc;
    for (int i = 0; i < K; ++i) {
        cin >> num;
        if (num == 0) {
            // 정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.
            stc.pop();
        } else {
            stc.push(num);
        }
    }

    unsigned long long sum = 0;
    while(!stc.empty()) {
        sum = sum + stc.top();
        stc.pop();
    }

    cout << sum;
    return 0;
}