#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, num;
    int max = -1000000; /* 초기화 -> 나올 수 있는 가장 작은 수 */
    int min = 1000000; /* 초기화 -> 나올 수 있는 가장 큰 수 */

    cin >> N;
    while (N--) {
        cin >> num;
        if (max < num) max = num;
        if (min > num) min = num;
    }

    cout << min << " " << max << endl;

    return 0;
}