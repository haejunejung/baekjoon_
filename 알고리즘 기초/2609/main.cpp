#include <iostream>

int maxnum (int A, int B, int a, int b) {
    if (A * a == B * b) return A * a;

    if (A * a > B * b) return maxnum(A, B, a, b+1);
    else return maxnum(A, B, a+1, b);
}

int minnum (int A, int B) {
    int n = 1;

    for (int i = 2; i <= std::min(A,B); ++i)
    {
        if (A % i == 0 && B % i == 0) n = i;
    }

    return n;
}

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B;
    cin >> A >> B;

    int min = minnum(A,B);
    int max = maxnum(A,B,1,1);

    cout << min << endl << max << endl;
    return 0;
}