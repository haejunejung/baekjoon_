#include <iostream>

using namespace std;

int distance (const int x1, const int y1, const int x2, const int y2) {
    return ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int exit = 0; /* 출발지 원을 나갈 때의 횟수 */
        int enter = 0; /* 도착지 원을 들어갈 때의 횟수 */

        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            int start_d = distance(x1, y1, cx, cy);
            int end_d = distance(x2, y2, cx, cy);

            if (start_d < r*r && end_d > r*r) exit++; /* 출발지가 원 안에 있고, 도착지가 원 밖에 있을 때 */
            if (end_d < r*r && start_d > r*r) enter++; /* 도착지가 원 안에 있고, 출발지가 원 밖에 있을 때 */
        }

        cout << exit + enter << "\n";
    }    

    return 0;
}