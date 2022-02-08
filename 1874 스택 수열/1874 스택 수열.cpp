#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <int> stk;
    string str;
    bool Istrue = true;
    int current = 0, n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;

        if (data > current) {
            while (true) {
                if (data == current) break;
                stk.push(++current);
                str += "+";
            }
        } 
        
        if (data <= current) {
            if (stk.empty()) {
                Istrue = false;
                break;
            } else if (stk.top() == data) {
                stk.pop();
                str += "-";
            }  else {
                Istrue = false;
                break;
            }
        }
    }

    if (Istrue == true) {
        for (int i = 0; i < str.length(); ++i) {
            cout << str[i] << '\n';
        }
    } else {
        cout << "NO" ;
    }

    return 0;

}