#include <iostream>
#include <cstring>
int main () {
    using namespace std;

    string a,b;
    cin >> a >> b;
    int ans = 0;
    int sub = b.length() - a.length();

    for (int i = 0; i <= sub; i++) {
        int count = 0;
        for (int j = 0; j < a.length(); ++j) {
            if (a[j] == b[j+i]) {
                count++;
            }
        }
        ans = ans<=count ? count : ans;
    }

    ans += sub;
    ans = b.length() - ans;
    cout << ans;
    return 0;
}