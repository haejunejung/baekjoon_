#include <iostream>
#include <stack>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    // 배열로도 풀 수 있지만, stack으로 푸는게 더 쉬울 것 같아서 stack으로 구현함 // 
    int arr[N];
    stack <int> stc;
    stack <int> ans;

    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; --i) {
        if (stc.empty()) {
            ans.push(-1);
            stc.push(arr[i]);
        } 
        
        else {
            while (true) {
                if (stc.empty() || stc.top() > arr[i]) break;
                stc.pop();
            }

            if (stc.empty()) ans.push(-1);
            else ans.push(stc.top());
            stc.push(arr[i]);
        }


    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;

}