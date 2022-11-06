#include <iostream>

#define MAX 21

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i,j,k;
    int w[MAX][MAX][MAX];
    
    for(i=0; i<MAX; ++i) {
        for(j=0; j<MAX; ++j) {
            for(k=0; k<MAX; ++k) {
                if (i==0 || j==0 || k==0) w[i][j][k] = 1;

                else if (i<j && j<k) w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];

                else w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
            }
        }
    }

    while (true) {
        int a,b,c, res;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        if (a <= 0 || b <= 0 || c <= 0) res = w[0][0][0];
        else if (a > 20 || b > 20 || c > 20) res = w[20][20][20];
        else res = w[a][b][c];

        cout << "w(" << a << ", " << b << ", " << c << ") = " << res << "\n";
    }

    return 0;
}