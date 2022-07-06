#include <iostream>
#include <algorithm>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int *rope = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> rope[i];
    }

    sort(rope, rope+n, less<>());
    int max = 0;

    for (int i = 0; i < n; ++i) {
        int temp = rope[i] * (n-i);
        if (max < temp) max = temp;
    }

    cout << max;

    return 0;
}