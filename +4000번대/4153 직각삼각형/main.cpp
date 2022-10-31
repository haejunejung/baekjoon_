#include <iostream>

using namespace std;

int longest (int a, int b, int c) {
    int ans = a;
    if (ans < b) ans = b;
    if (ans < c) ans = c;

    return ans;
}

void isTriangle (int a, int b, int c) {
    if (a*a + b*b == c*c) cout << "right" << "\n";
    else cout << "wrong" << "\n";
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        if (a == longest(a,b,c)) isTriangle(b,c,a);
        else if (b == longest(a,b,c)) isTriangle(a,c,b);
        else isTriangle(a,b,c);
    }

    return 0;
}