#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase, num, remainder, res = 0;
    int count[42] = { };
    
    for (testcase = 1; testcase <= 10; testcase++) {
        cin >> num;
        remainder = num % 42;
        count[remainder]++;
    }

    for (testcase = 0; testcase < 42; testcase++) {
        if (count[testcase] > 0) res++;
    }

    cout << res << endl;
    

    return 0;
}