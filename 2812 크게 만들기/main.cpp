#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K;
    cin >> N >> K;
    
    int count = N-K;

    /* 50만 자리의 수를 넣을 수 없어서 string으로 받는다 */
    string str;
    cin >> str;

    int *number = new int[N];
    for (int i = 0; i < N; ++i)
        number[i] = str[i]-'0';

    deque <int> dq;
    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && K && dq.back() < number[i]) {
            dq.pop_back();
            K--;
        }

        dq.push_back(number[i]);
    }

    while (!dq.empty() && count > 0) {
        count--;
        cout << dq.front();
        dq.pop_front();
    }
    
    return 0;
}