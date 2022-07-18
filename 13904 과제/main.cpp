#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare (pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    /* 
        하루에 한 과제만 끝낼 수 있다.
        마감일이 지난 과제는 점수를 받을 수 없다.
    */

    vector <pair<int,int>> v;
    for (int i = 0; i < N; ++i) {
        int d,w;
        cin >> d >> w;
        v.push_back(make_pair(d,w));
    }

    bool days[1001];
    fill_n(days, 1001, false);

    sort (v.begin(), v.end(), compare);

    // for (int i = 0; i < N; ++i) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int f = v[i].first;
        int s = v[i].second;
        if (!days[f]) {
            days[f] = true;
            ans += s;
        } 
        else {
            for (int j = f-1; j > 0; --j) {
                if (!days[j]) {
                    days[j] = true;
                    ans += s;
                    break;
                }
            }
        }
    }

    cout << ans;
    
    

    return 0;
}