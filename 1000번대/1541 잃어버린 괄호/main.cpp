#include <iostream>
#include <cstring>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    string str;
    string arr[51];
    size_t cnt = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '+' || input[i] == '-') {
            arr[cnt++] = str;
            arr[cnt++] = input[i];
            str.clear();
        } else {
            str += input[i];
        }
    }

    if (!str.empty()) {
        arr[cnt] = str;
    }

    int ans = stoi(arr[0]);
    for (size_t i = 1; i < cnt; ++i) {
        if (arr[i] == "+") ans = ans + stoi(arr[i+1]);
        else if (arr[i] == "-") {
            i++;
            int temp = stoi(arr[i]);
            while (i < cnt && arr[i] != "-")
            {
                if (arr[i] == "+") temp += stoi(arr[i+1]);
                i++;
            }
            i--;
            ans += -temp;
        }
    }

    cout << ans;
    
    return 0;
}