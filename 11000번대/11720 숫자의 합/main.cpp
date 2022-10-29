#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, sum = 0;
    cin >> N;

    string str;
    cin >> str;

    for (int i = 0; i < N; ++i) {
        sum += str[i] - '0';
    }

    cout << sum;

    return 0;
}