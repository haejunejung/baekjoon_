#include <iostream>

#define E 1
#define W 2
#define S 3
#define N 4

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int order[6];
    int direction[6];
    int x = 0, y = 0, dx = 0, dy = 0;

    int n;
    cin >> n;

    for (int i = 0; i < 6; ++i) {
        int dir, val;
        cin >> dir >> val;

        direction[i] = dir; /* 방향 저장 */
        order[i] = val; /* value 저장 */

        if (dir == E || dir == W) {
            x = max(x, val); /* 큰 직사각형의 x길이 */
        }
        else {
            y = max(y, val); /* 큰 직사각형의 y길이 */
        }
    }

    /* 
        현재 가는 방향이 어디로 가던 이전 방향과 이후 방향이 같다면, 이것의 길이가 작은 직사각형의 변 중 하나라는 것을 알 수 있다
        -> E,W의 방향으로 간다면, 작은 직사각형의 x길이, S,N의 방향으로 간다면, 작은 직사각형의 y길이이다
        -> 큰 직사각형에서 작은 직사각형의 넓이를 뺀 후, 면적당 참외의 수를 곱한다면 답이 나올 것이다
    */
    for (int i = 0; i < 6; ++i) {
        if (direction[i] == E || direction[i] == W) {
            if ((direction[(i-1+6)%6] == S && direction[(i+1)%6] == S) ||
                (direction[(i-1+6)%6] == N && direction[(i+1)%6] == N)) {
                    dx = order[i];
                }
        }
        else {
            if ((direction[(i-1+6)%6] == E && direction[(i+1)%6] == E) ||
                (direction[(i-1+6)%6] == W && direction[(i+1)%6] == W)) {
                    dy = order[i];
                }
        }
    }

    cout << n * (x*y - dx*dy) << endl;
    return 0;
}