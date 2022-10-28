#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase, num, v, cnt = 0;
    cin >> T;

    /* 방법 1 */
    int array[100];
    for (testcase = 0; testcase < T; testcase++) { /* 저장 */
        cin >> num;
        array[testcase] = num;
    }

    cin >> v;

    for (testcase = 0; testcase < T; testcase++) { /* v와 같은 수 찾기 */
        if (array[testcase] == v) cnt++;
    }

    cout << cnt;

    /* 방법 2*/
    // int *array = new int[T];
    // for (testcase = 0; testcase < T; testcase++) {
    //     cin >> num;
    //     *(array+testcase) = num;
    // }

    // cin >> v;

    // for (testcase = 0; testcase < T; testcase++) {
    //     if (*(array+testcase) == v) cnt++; 
    // }

    // cout << cnt;

    return 0;
}