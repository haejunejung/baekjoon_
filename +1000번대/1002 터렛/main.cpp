#include <iostream>
#include <cmath>

using namespace std;

double distance (const int x1, const int y1, const int x2, const int y2) {
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
        int rm = (r2-r1) * (r2-r1);
        int rp = (r2+r1) * (r2+r1);

        if (d > rm && d < rp) {
            cout << 2 << "\n"; /* 두 점이 만날 때 */
        } else if (d == rp) {
            cout << 1 << "\n"; /* 외접 */
        } else if (d == rm && d != 0) {
            cout << 1 << "\n"; /* 내접 */
        } else if (d < rm) {
            cout << 0 << "\n"; /* 두 원이 만나지 않는다 (내부) */
        } else if (d > rp) {
            cout << 0 << "\n"; /* 두 원이 만나지 않는다 (외부) */
        } else { 
            cout << -1 << "\n"; /* 동일원일 때 */
        }
    }
    return 0;
}