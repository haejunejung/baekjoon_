#include <iostream>

#define Max 21
#define inf 100000000

using namespace std;

int N, S[Max][Max], ans = inf;

void Initialize () {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> S[i][j];
        }
    }
}

// 한 쪽이 1명 ~ N/2명이 될 떄까지 구해야됨 // 

void DFS (int cnt, int pos, int range, bool check[]) {
    if (cnt == range) {
        int start = 0, link = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (check[i] == true && check[j] == true) start += S[i][j];
                if (check[i] == false && check[j] == false) link += S[i][j];
            } 
        }
        ans = min (ans, abs(start - link));
        return;
    } 

    for (int i = pos; i < N; ++i) {
        check[i] = true;
        DFS (cnt + 1, i + 1, range, check);
        check[i] = false;
    }
}

void Solution () {
    // start 팀의 사람 수 // 
    for (int i = 0; i < N; ++i) {
        bool check[Max];
        DFS (0,1,i, check);
    }

    cout << ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize ();
    Solution ();
    return 0;
}