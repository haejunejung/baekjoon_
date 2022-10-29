#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned long long fiboNum[21];
    fiboNum[0] = 0;
    fiboNum[1] = 1;
    
    for (int i = 2; i <= 20; ++i) {
        fiboNum[i] = fiboNum[i-1] + fiboNum[i-2];
    }

    int n;
    cin >> n;
    cout << fiboNum[n];

    return 0;
}