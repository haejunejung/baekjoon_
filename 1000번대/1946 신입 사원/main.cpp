#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector <pair<int,int>> v;
        for (int i = 0; i < N; ++i) {
            int a,b;
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(), v.end(), less<>());
        int rank = v.front().second;
        int count = 1;

        for (int i = 1; i < N; ++i) {
            if (v[i].second < rank) {
                count++;
                rank = v[i].second;
            }
        }   
        
        cout << count << '\n';
    }

    return 0;
}