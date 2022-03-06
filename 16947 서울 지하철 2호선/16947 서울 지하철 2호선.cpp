#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define Max 3001

using namespace std;

int n, ans[Max];
bool flag, Visit[Max], Circle[Max];
vector <int> vec[Max];

void Input () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        ans[i] = 0;
    }
}

void Output () {
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}

void DFS (int target_point, int start, int count) {
    
    if (start == target_point && count >= 2) {
        flag = true;
        return;
    }

    Visit[start] = true;

    for (int i = 0; i < vec[start].size(); ++i) {
        int next = vec[start][i];

        // 한번도 거치지 않았다면 // 
        if (!Visit[next]) {
            DFS (target_point, next, count + 1);
        }

        // 한번이라도 거쳤다면 //
        else {
            if (next == target_point && count >= 2) {
                DFS (target_point, next, count);
            }
        }

        if (flag) return;
    }

}

void BFS (int start, int cnt) {
    queue < pair<int,int> > que;
    que.push(make_pair(start,cnt));
    Visit[start] = true;

    while (!que.empty()) {
        int Cur = que.front().first;
        int Cnt = que.front().second;
        que.pop();

        if (Circle[Cur]) {
            ans[start] = Cnt;
            break;
        }

        for (int i = 0; i < vec[Cur].size(); ++i) {
            int next = vec[Cur][i];
            if (!Visit[next]) { 
                Visit[next] = true;
                que.push(make_pair(next, Cnt+1));
            }
        }
    }
}

void Solution () {
    for (int i = 1; i <= n; ++i) {
        memset (Visit, false, sizeof(Visit));
        flag = false;

        DFS (i,i,0);
        if (flag) Circle[i] = true;
    }

    for (int i = 1; i <= n; ++i) {
        memset (Visit, false, sizeof(Visit));
        if (!Circle[i]) {
            BFS (i, 0);
        } 
    }

    Output ();
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();

    return 0;
}