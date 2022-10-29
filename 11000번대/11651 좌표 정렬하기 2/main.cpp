#include <iostream>
#include <algorithm>
#include <utility>

#define MAX 100000

using namespace std;

static int N;
std::pair<int, int> point[MAX];

bool compare (std::pair<int,int> &a, std::pair<int,int> &b) {
    if (a.second == b.second) { /* y좌표가 같다면, */
        return a.first < b.first; /* x좌표가 작은게 앞으로 */
    }
    return a.second < b.second; /* y좌표가 작은게 앞으로 */
}

void solve () {
    sort(point, point+N, compare); /* 정렬 알고리즘 사용 , compare로 조건 만들기 */

    for (int i = 0; i < N; ++i) {
        cout << point[i].first << " " << point[i].second << "\n";
    }
    return;
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x,y;
        cin >> x >> y;
        point[i] = make_pair(x,y); /* x,y를 pair로 받게함*/
    }
    return;
}

int main (void) {
    input ();
    solve ();

    return 0;
}