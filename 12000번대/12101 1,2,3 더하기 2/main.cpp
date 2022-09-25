#include <iostream>

using namespace std;

int n, k, cnt; /* n,k는 input cnt는 횟수 */
int method[12]; /* 1~3까지 넣을 배열 */

void solution (int sum, int count) {
    if (sum == n) {
        cnt++;
        if (cnt == k) {
            for (int i = 1; i < count; ++i) {
                cout << method[i];
                if (i < count-1) cout << "+";
            }
            exit(0); /* 정답이 있다면 여기서 종료 */
        }
    }

    for (int i = 1; i <= 3; ++i) {
        if (sum + i <= n) {
            method[count] = i;
            solution(sum + i, count+1);
            method[count] = 0; /* 없어도 무방하나, 보기 편하기 위해서 0으로 초기화 */
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cnt = 0;
    solution (0, 1);

    cout << -1; /* 정답이 없을 경우 -1 출력 */
    return 0;
}