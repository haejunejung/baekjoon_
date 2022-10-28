#include <iostream>
#include <string>

using namespace std;

int k, ans[10];
long long Max = 0, Min = 9567843012;
bool check[10];
char arr[10];
string Max_ans, Min_ans;

void Initialize () {
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }
}

void DFS (int cnt) {
    if (cnt == k + 1) {
        string str;
        char ch;
        for (int i = 0; i <= k; ++i) {
            ch = (char)(ans[i] + '0');
            str += ch;
        }

        if (Max < stoll(str)) {
            Max = stoll(str);
            Max_ans = str;
        }

        if (Min > stoll(str)) {
            Min = stoll(str);
            Min_ans = str;
        }

        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (check[i] == false) {

            if (cnt == 0) {
                check[i] = true;
                ans[cnt] = i;
                DFS (cnt + 1);
                check[i] = false;  
            }

            else {

                if (arr[cnt-1] == '<') {
                    if (ans[cnt-1] < i) {
                        check[i] = true;
                        ans[cnt] = i;
                        DFS (cnt + 1);
                        check[i] = false;
                    }
                }

                else if (arr[cnt-1] == '>') {
                    if (ans[cnt-1] > i) {
                        check[i] = true;
                        ans[cnt] = i;
                        DFS (cnt + 1);
                        check[i] = false;
                    }
                }
            }
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize ();
    DFS (0);
    cout << Max_ans << '\n' << Min_ans;
    return 0;
}