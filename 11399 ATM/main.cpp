#include <iostream>
#include <algorithm>

#define ll long long
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    int *time = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> time[i];
    }

    sort(time, time+N, less<>());

    int sum = 0;
    int *ans = new int[N];
    for (int i = 0; i < N; ++i) {
        sum += time[i];
        ans[i] = sum;
    }

    sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += ans[i];
    }

    cout << sum;
    return 0;
}