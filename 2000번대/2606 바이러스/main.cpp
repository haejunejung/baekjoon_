#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int ComputerNum, ConnectionNum;
bool check[101];
vector <int> connect[101];

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> ComputerNum >> ConnectionNum;
    for (int i = 0; i < ConnectionNum; ++i) {
        int start, end;
        cin >> start >> end;
        connect[start].push_back(end);
        connect[end].push_back(start);
    }
}

void solution () {
    int count = 0;
    queue <int> q;
    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int start = q.front();
        q.pop();

        for (int i = 0; i < connect[start].size(); ++i) {
            int end = connect[start][i];
            if (!check[end]) {
                check[end] = true;
                q.push(end);
                count++;
            }
        }
    }

    cout << count;
}

int main (void) {
    input ();
    solution ();
    return 0;
}