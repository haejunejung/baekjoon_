#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 101
#define type int /* long long 같은 형은 필요없다고 생각해서 모두 int로 통일하였다 */

using namespace std;
vector <pair<type,type>> v; /* 전깃줄의 정보 */
type dp[MAX]; 

bool compare (pair<type,type> &a, pair<type,type> &b) {
    return a.first < b.first;
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    type T, testcase;
    cin >> T;

    for(testcase=0; testcase<T; ++testcase) {
        type A, B;
        cin >> A >> B;

        v.push_back(make_pair(A,B));
    }

    sort(v.begin(), v.end(), compare); /* A의 오름차순으로 정렬 -> B의 가장 긴 증가하는 부분 수열을 구할 수 있도록 함 */
    fill_n(dp, MAX, 1); /* 부분 수열은 최소 1의 길이를 가지므로 1로 초기화 */
}

void solve () {
    type i,j;

    for(i=0; i<v.size(); ++i) {
        for(j=i-1; j>=0; --j) {
            if (v[i].second > v[j].second) {
                dp[i] = max(dp[i], dp[j]+1); /* 가장 긴 증가하는 부분 수열 만들기 */
            }
        }
    }

    type maximum = 0;
    for(i=0; i<v.size(); ++i) {
        if (dp[i] > maximum) maximum = dp[i]; /* 가장 긴 증가하는 부분 수열 구하기 */
    }

    /* 가장 긴 증가하는 부분 수열 -> 없애지 않아도 되는 전깃줄의 정보이기 때문에 전체-가장 긴 증가하는 부분 수열 길이가 정답이 된다 */
    cout << v.size() - maximum; 
}

int main (void) {

    input ();
    solve ();
    return 0;
}