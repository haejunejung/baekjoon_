#include <iostream>

using namespace std;

/* 최대 공약수 */
int GCD (int a, int b){
    if (b == 0) return a;
    else return GCD (b, a%b);
}

/* 최소 공배수 */
int LCM (int a, int b){
    return a*b / GCD(a,b);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int *ring = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> ring[i];
    }

    for (int i = 1; i < N; ++i) {
        int lcm = LCM(ring[i], ring[0]);

        cout << lcm / ring[i] << "/" << lcm / ring[0] << "\n";
    }

    return 0;
}