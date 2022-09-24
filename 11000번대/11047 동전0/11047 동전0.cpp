#include <iostream>
using namespace std;

#define Max 10

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int price[Max];

    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }    

    int count = 0;
    for (int j = N - 1; j >= 0; --j) {
        if (K >= price[j]) {
            count = count + (K / price[j]);
            K %= price[j];
        } 
    }

    cout << count << endl;

    return 0;
}