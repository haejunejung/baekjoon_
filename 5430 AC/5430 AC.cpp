#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        string func;
        cin >> func;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque <int> dq;

        int cnt = 0;
        while (true) {
            if (arr[cnt] == ']' || arr == "[]") break;
            string s;
            while (true) {
                if (arr[cnt] == '[') {
                    cnt++;
                }
                else if (arr[cnt] == ',') {
                    cnt++;
                    break;
                }
                else if (arr[cnt] == ']') {
                    break;
                } 
                else {
                    s += arr[cnt];
                    ++cnt;
                }
            }
            int data = stoi(s);
            dq.push_back(data);
        }

        int cnt_R = 0, cnt_D = 0;
        bool IsError = true;
        for (int j = 0; j < func.length(); ++j) {
            if (func[j] == 'R') {
                cnt_R++;
            }

            else if (func[j] == 'D') {
                cnt_D++;
                if (cnt_D > n) {
                    IsError = false;
                    break;
                } else {
                    if (cnt_R % 2 == 0) {
                        if (dq.empty() == false) {
                            dq.pop_front();
                        } else {
                            IsError = false;
                        }
                    } else {
                        if (dq.empty() == false) {
                            dq.pop_back();
                        } else {
                            IsError = false;
                        }
                    }
                }
            }
        }

        if (n < cnt_D) IsError = false;
        if (IsError == true) {
            cout << '[';
            if (cnt_R % 2 != 0) {
                while(true) {
                    if (dq.empty() == true) break;
                    cout << dq.back();
                    dq.pop_back();
                    if (dq.empty() == true) break;
                    cout << ',';
                }
            } else {
                while(true) {
                    if(dq.empty() == true) break;
                    cout << dq.front();
                    dq.pop_front();
                    if (dq.empty() == true) break;
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        } else {
            cout << "error" << '\n';
        }
    }
    return 0;  
}