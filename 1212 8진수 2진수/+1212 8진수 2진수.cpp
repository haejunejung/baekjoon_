#include <iostream>
#include <stack>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    // error 방지 // 
    if (str == "0") {
        cout << 0;
        return 0;
    }

    // stack 이용한 풀이 // 
    stack <int> stk;
    for (int i = str.length()-1; i >= 0; --i) {
        int n = str[i] - '0';
        for (int j = 0; j < 3; ++j) {
            stk.push(n%2);
            n /= 2;
        }
    }

    while (true) {
        if (stk.top() == 0) stk.pop();
        else break;
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}