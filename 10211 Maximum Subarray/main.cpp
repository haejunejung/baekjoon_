#include <iostream>

int main (void) 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase)
    {
        int N;
        cin >> N;

        int *arrX = new int[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> arrX[i];
        }

        int sum = arrX[0];
        for (int i = 1; i < N; ++i)
        {
            arrX[i] = max(arrX[i-1]+arrX[i], arrX[i]);
            if (sum < arrX[i]) sum = arrX[i];
        }

        cout << sum << "\n";
    }
    return 0;
}