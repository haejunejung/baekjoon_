#include <iostream>
#include <iostream>
#define ll long long

using namespace std;

pair <ll,ll> Cnt (ll x) {
    pair <ll,ll> cnt (0,0);
    for (ll i = 2; i <= x; i*=2) {
        cnt.first += x / i;
    }

    for (ll i = 5; i <= x; i*=5) {
        cnt.second += x / i;
    }

    return cnt;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    pair <ll,ll> cnt_n = Cnt(n);
    pair <ll,ll> cnt_nm = Cnt(n-m);
    pair <ll,ll> cnt_m = Cnt(m);

    ll cnt_two = cnt_n.first - (cnt_nm.first + cnt_m.first);
    ll cnt_five = cnt_n.second - (cnt_nm.second + cnt_m.second);

    cout << min (cnt_two,cnt_five);
    return 0;
}