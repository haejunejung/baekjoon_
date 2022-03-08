#include <iostream>
#include <queue>
#include <vector>

#define Max 100001
#define wrong 0
#define right 1

using namespace std;

int N;
queue <int> que, ans;
vector <int> vec[Max];
bool Visit[Max];

void Input () {
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int x,y;
        cin >> x >> y;

        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        ans.push(x);
    }
}

int Solve () {
    if (ans.front() != 1) return wrong;

    que.push(ans.front());
    ans.pop();

    while (!ans.empty()) {
        int idx = que.front();
        que.pop();
        Visit[idx] = true;

        int child_cnt = vec[idx].size();
        for (size_t s = 0; s < vec[idx].size(); ++s) {
            int next = vec[idx][s];
            if (Visit[next]) child_cnt--;
        }

        while (child_cnt) {
            vector <int>::iterator iter = find(vec[idx].begin(), vec[idx].end(), ans.front());
            if (iter == vec[idx].end()) return wrong;
            else {
                --child_cnt;
                ans.pop();
            }
        }
    }

    return right;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    cout << Solve ();

    return 0;
}