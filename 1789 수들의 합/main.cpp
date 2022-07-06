#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned long long S;
    cin >> S;

    unsigned long long sum = 0, max = 0;
    while (S >= sum) {
        max++;
        sum += max;
    }

    cout << max-1;
    return 0;
}