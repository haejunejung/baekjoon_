#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        string function_p;
        cin >> function_p;

        deque <int> dq;

        int n;
        cin >> n;

        string digit_arr;
        cin >> digit_arr;

        // deque에 정수 담기 // 
        for (int j = 0; j < digit_arr.length(); ++j) {
            string digit;
            while (isdigit(digit_arr[j])) {
                digit += digit_arr[j++];
            }

            if (digit.empty() == false) {
                dq.push_back(stoi(digit));
            }
        }

        // 숫자가 잘 나오는지 test //
        // while (!dq.empty()) {
        //     cout << dq.front() << ' ';
        //     dq.pop_front();
        // }

        // function execute // 
        bool flag = true; // true는 정방향 false는 역방향으로 구분
        bool IsError = false;
        for (int k = 0; k < function_p.length(); ++k) {
            if (function_p[k] == 'R') flag = !flag;
            else {

                if (dq.empty() == true) {
                    IsError = true;
                    break;
                } 

                else {
                    if (flag == true) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if (IsError == true) cout << "error" << '\n';
        else {
            cout << '[';
            if (flag == true) {
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (dq.empty() == false) cout << ',';
                }
            }

            else {
                while (!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (dq.empty() == false) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
    return 0;
}

// AC 만들기

// 1. 배열을 사용해도 상관없으나 , 삽입과 삭제에 유연한 링크드 리스트로 구현
// 2. 링크드 리스트 중에서도 stack , queue , deque 중 양방향 접근이 가능한 deque 사용
// 3. R의 개수가 짝수이면 front -> back 순으로 D 연산
// 4. R의 개수가 홀수이면 back -> front 순으로 D 연산
// 5. [x1,x2,x3, ... ,xn] 의 정수를 담을 deque 필요.