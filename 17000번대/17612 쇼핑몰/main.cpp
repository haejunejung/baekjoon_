#include <iostream>
#include <queue>

using namespace std;

struct test
{
    int x;
    int y;
    int z;
};


struct compare
{
    bool operator() (test &a, test &b) {
        if (a.x == b.x) {
            return a.y > b.y;
        }
        return a.x > b.x;
    }
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    priority_queue<test, vector<test>, compare> pq;
    priority_queue<test, vector<test>, compare> q;
    /* 
        먼저 온 사람이 계산대 앞 쪽에 (1,2,3,...) 위치
        계산을 마치는 시간이 동일 하다면 계산대 뒤 쪽부터 나감 (k,k-1,k-2,...)
    */

    for (int order = 0; order < N; ++order) {
        int id, w;
        cin >> id >> w;
        // w / order / id // 
        if (order < k) {
            pq.push(test({w, order, id}));
        } 
        else {
            test info = pq.top();
            pq.pop();
            pq.push(test({w+info.x, info.y, id}));
            q.push(test({info.x, -info.y, info.z}));
        }
    }

    while (!pq.empty()) {
        test info = pq.top();
        pq.pop();
        q.push(test({info.x, -info.y, info.z}));
    }

    long long ans = 0, count = 1;
    while (!q.empty()) {
        // cout << q.top().z << endl;
        ans = ans + count * q.top().z;
        count++;
        q.pop();
    }

    cout << ans;


    return 0;
}