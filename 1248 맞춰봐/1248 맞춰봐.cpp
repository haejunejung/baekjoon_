#include <iostream>

using namespace std;

int N;

void DFS (char arr[], int ans[], int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N; ++i) {
            cout << ans[i];
        }
        cout << '\n';
    }

    
}


int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;

    int Max = (N * (N+1)) / 2;
    char arr[Max];
    int ans[Max];

    for (int i = 0; i < Max; ++i) {
        cin >> arr[i];
    }

    DFS (arr, ans, 0);

    return 0;
}