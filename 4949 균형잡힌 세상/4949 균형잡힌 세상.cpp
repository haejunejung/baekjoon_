#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin,str,'\n')) {
        stack <char> stc;
        if (str == ".") break;
        bool Istrue = true; // false 이면 no 출력 , true 이면 yes 출력
        
        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (c == '(' || c == '[') stc.push(c);
            else if (c == ')') {
                if (stc.size() > 0 && stc.top() == '(') {
                    Istrue = true;
                    stc.pop();
                }
                else {
                    Istrue = false; 
                    break;
                }
            } else if (c == ']') {
                if (stc.size() > 0 && stc.top() == '[') {
                    Istrue = true;
                    stc.pop();
                }
                else {
                    Istrue = false;
                    break;
                }
            }
        }

        if (stc.empty() && Istrue == true) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}