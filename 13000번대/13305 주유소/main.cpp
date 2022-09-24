#include <iostream>
#include <climits>
#include <utility>
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    size_t N;
    cin >> N;

    size_t *dis = new size_t[N];
    size_t *money = new size_t[N+1];
    for (size_t i = 1; i < N; ++i) {
        cin >> dis[i];
    }  
    for (size_t i = 1; i <= N; ++i) {
        cin >> money[i];
    }

    size_t ans = 0;
    size_t greedy = SIZE_MAX;

    for (size_t i = 1; i < N; ++i) {
        if (money[i] < greedy) {
            greedy = money[i];
        }
        ans += greedy * dis[i];
    }

    cout << ans;

    return 0;
}