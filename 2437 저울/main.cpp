#include <iostream>
#include <algorithm>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int *input = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    sort (input, input+N, less<>());

    int res = 1;
    for (int i = 0; i < N; ++i) {
        if (input[i] > res) break;
        res += input[i];
    }

    cout << res;
    return 0;
}