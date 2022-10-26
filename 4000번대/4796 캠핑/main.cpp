#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase = 1;
    while (true)
    {
        int L, P, V;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        
        cout << "Case " << testcase << ": ";
        if (V%P > L) cout << (V/P) * L + L << endl; /* V % P > L */
        else cout << (V/P) * L + V%P << endl; /* V % P <= L */
        testcase++;
    }

    // 5 8 20 => 1 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 1 ~ 
    // 5 (8-5) 5 (8-5) ... 
    // 위의 케이스에서는 5일 사용 후 3일 사용하지 못하고 다시 5일 사용 ... 반복이 이루어진다 
    // 즉 (V/P) * L 만큼 사용하고 이후의 남은 기간동안 어떻게 사용할지를 생각해보면
    // L일 만큼 사용할 수 있을 때와, 없을 때 (V % P) 로 나눌 수 있다.

    return 0;
}