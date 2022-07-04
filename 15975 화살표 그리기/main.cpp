#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> *vec = new vector<int>[N+1];
    for (int i = 0; i < N; ++i){
        int point, color;
        cin >> point >> color;

        vec[color].push_back(point);
    }

    for (int i = 1; i <= N; ++i){
        if (!vec[i].empty()){
            sort(vec[i].begin(), vec[i].end(), less<>());
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        int length = vec[i].size();
        if (!vec[i].empty() && length > 1){
            for (int j = 0; j < length; ++j) {
                if (j == 0) ans += vec[i][1] - vec[i][0];
                else if (j == length-1) ans += vec[i][length-1] - vec[i][length-2];
                else ans += std::min(vec[i][j+1]-vec[i][j], vec[i][j] - vec[i][j-1]);
                
            }
        } 
    }

    cout << ans;



    return 0;
}