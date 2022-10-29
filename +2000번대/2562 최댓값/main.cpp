#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase, num, max_num = -1, number = 0;
    for (testcase = 1; testcase <= 9; testcase++) {
        cin >> num;
        if (max_num < num) max_num = num, number = testcase;
    }

    cout << max_num << "\n" << number << endl;

    return 0;
}