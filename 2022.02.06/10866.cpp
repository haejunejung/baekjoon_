#include <iostream>
#include <string>
#include <deque>

// using deque STL //

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque <int> deq;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        if (str == "push_front") {
            int n; cin >> n;
            deq.push_front(n);
        } 
        
        else if (str == "push_back") {
            int n; cin >> n;
            deq.push_back(n);
        } 
        
        else if (str == "pop_front") {
            if (deq.empty() == true) cout << -1 << '\n';
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        } 
        
        else if (str == "pop_back") {
            if (deq.empty() == true) cout << -1 << '\n';
            else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        } 
        
        else if (str == "size") {
            cout << deq.size() << '\n';
        } 
        
        else if (str == "empty") {
            if (deq.empty() == true) cout << 1 << '\n';
            else cout << 0 << '\n';
        } 
        
        else if (str == "front") {
            if (deq.empty() == true) cout << -1 << '\n';
            else {
                cout << deq.front() << '\n';
            }
        } 
        
        else if (str == "back") {
            if (deq.empty() == true) cout << -1 << '\n';
            else {
                cout << deq.back() << '\n';
            }
        }
    }

    return 0;
}