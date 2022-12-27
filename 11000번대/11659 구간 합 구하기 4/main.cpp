#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, idx;
    cin >> N >> M;

    int *NumList = new int[N];
    unsigned long *SumList = new unsigned long[100001];
    SumList[0] = 0;

    for (idx = 0; idx < N; ++idx) {
        int num;
        cin >> num;

        NumList[idx] = num;
        SumList[idx+1] = SumList[idx] + num;
    }

    for (idx = 0; idx < M; ++idx) {
        int i, j;
        cin >> i >> j;
    
        unsigned long sum = SumList[j] - SumList[i-1];
        cout << sum << "\n";
    }

    return 0;
}