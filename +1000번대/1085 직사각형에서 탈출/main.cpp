#include <iostream>

using namespace std;

/* 두 수를 비교하여 작은 수를 return */
int compareNums (const int a, const int b) {
    if (a < b) return a;
    else return b;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int dx = compareNums(x, w-x); /* x축으로 짧은 거리 */
    int dy = compareNums(y, h-y); /* y축으로 짧은 거리 */
    cout << compareNums(dx, dy); /* x,y축 모두 중에서 제일 짧은 거리 */

    return 0;
}