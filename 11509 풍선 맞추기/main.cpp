#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    int H[1000001], count =0;
    fill_n(H, 1000001, 0);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        H[x]++;
        if (H[x+1] == 0) count++;
        else H[x+1]--;
    }
    cout << count;

    return 0;
}