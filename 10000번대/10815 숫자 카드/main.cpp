#include <iostream>
#include <map>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    map <int, int> map1;

    /* map에 정수를 저장한다 */
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        map1.insert({val, i});
    }

    int M;
    cin >> M;

    /* map에 정수가 저장되어있는지 확인한다 */
    for (int i = 0; i < M; ++i) {
        int val;
        cin >> val;
        if (map1.find(val) != map1.end()) cout << 1 << " "; /* 찾았다면, 1 출력 */
        else cout << 0 << " "; /* 못찾았다면, 0 출력 */
    }

    return 0;
}