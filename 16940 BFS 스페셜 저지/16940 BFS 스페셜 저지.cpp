#include <iostream>
#include <vector>
#include <queue>

#define Max 100001
#define wrong 0
#define right 1

using namespace std;

int N, order[Max];
bool Visit[Max];
queue <int> que, ans;
vector <int> vec[Max];

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

int Solution () {
    if (ans.front() != 1) return wrong;

    que.push(ans.front());
    ans.pop();
    
    while (!ans.empty()) {
        int idx = que.front();
        que.pop();
        Visit[idx] = true;

        int idx_cnt = 0;
        for (size_t s = 0; s < vec[idx].size(); ++s) {
            int next = vec[idx][s];
            if (!Visit[next]) {
                ++idx_cnt;
                order[next] = idx;
            }
        }

        while (idx_cnt) {
            int test_idx = ans.front();
            if (order[test_idx] == idx) {
                --idx_cnt;
                que.push(test_idx);
                ans.pop();
            } 
            
            else {
                return wrong;
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
    cout << Solution ();

    return 0;
}