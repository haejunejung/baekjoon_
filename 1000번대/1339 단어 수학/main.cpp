#include <iostream>
#include <algorithm>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    string *input = new string[N];
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    int flag[26];
    fill_n(flag, 26, 0);
    for (int i = 0; i < N; ++i) {
        int pow = 1;
        for (int j = input[i].length()-1; j >= 0; --j) {
            flag[input[i][j]-'A'] += pow;
            pow *= 10;
        }
    }

    sort (flag, flag+26, greater<>());

    int res = 0, count = 9;
    for (int i = 0; i < 26; ++i) {
        res += flag[i] * count;
        count--;
    }

    cout << res;

    return 0;
}