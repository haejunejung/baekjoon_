#include <iostream>

int MaxNum (int A, int B, int a, int b)
{
    if (A * a == B * b) return A * a;

    if (A * a > B * b) return MaxNum(A, B, a, b+1);
    else return MaxNum(A, B, a+1, b);
}

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase)
    {
        int A, B;
        cin >> A >> B;
        
        cout << MaxNum(A,B,1,1) << "\n";
    }

    return 0;
}