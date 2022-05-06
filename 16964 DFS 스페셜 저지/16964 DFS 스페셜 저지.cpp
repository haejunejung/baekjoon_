#include <iostream>
#include <vector>
#include <queue>

#define Max 100001
#define wrong 0
#define right 1

using namespace std;

int N;
vector <int> Vec[Max];
queue <int> que;
bool Visit[Max], flag;

void Input () {
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int a,b;
        cin >> a >> b;

        Vec[a].push_back(b);
        Vec[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        que.push(a);
    }
}

void dfs (int point) {
    if (Visit[point]) return;
    Visit[point] = true;

    while (!que.empty()) {
        
    }

    for (size_t s = 0; s < Vec[point].size(); ++s) {
        int next = Vec[point][s];
        if (!Visit[next]) {
            Vec[point].erase(Vec[point].begin() + s);
            dfs (next);
        }
    }
}

void Solve () {
    if (que.front() != 1) {
        cout << wrong;
        return;
    }

    dfs (1);

    if (flag) cout << wrong;
    else cout << right;    

}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solve ();

    return 0;
}