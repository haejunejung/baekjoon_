#include <iostream>
#define ll long long
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // int 형으로 했다가 틀렸음 //
    // W가 long long 형으로 만들어져야 함 //
    ll n, W, count;
    cin >> n >> W;

    ll *coin = new ll[n];
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    for (int i = 0; i < n-1; ++i) {
        if (coin[i] < coin[i+1]) {
            count = W / coin[i];
            W %= coin[i];
            W += coin[i+1] * count;
        }
    }

    cout << W;


    return 0;
}