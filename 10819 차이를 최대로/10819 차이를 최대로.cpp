#include <iostream>

#define Max 9
using namespace std;

int n, maximum = 0;
int arr[Max] = { }, ans[Max] = { };
bool visited[Max] = { };

void Initialize () {
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int calculator () {
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += abs(ans[i] - ans[i+1]);
    }

    return sum;
}

void Solution (int cnt) {
    if (cnt == n) {
        maximum = max(maximum, calculator());
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == false) {
            visited[i] = true;
            ans[cnt] = arr[i];
            Solution(cnt + 1);
            visited[i] = false;
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize();
    Solution(0);

    cout << maximum;
    return 0;
}