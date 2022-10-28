#include <iostream>

using namespace std;

int purpose_N;

int cycle_length (int new_N, int length) {
    if (purpose_N == new_N) return length; /* base case 목표 N과 현재 N이 같다면 종료 */
    else {
        if (new_N / 10 == 0) return cycle_length(new_N * 10 + new_N, length + 1); /* 현재 N이 10보다 작다면, */
        else return cycle_length((new_N % 10) * 10 + ((new_N / 10) + (new_N % 10)) % 10, length+1); /* 현재 N이 10보다 크거나 같다면, */
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> purpose_N;

    int new_N;

    /* 처음에 만들어지는 새로운 수를 먼저 구한 후 recursion */
    if (purpose_N / 10 == 0) new_N = purpose_N * 10 + purpose_N; /* 10보다 작을 때 새로운 수 */
    else new_N = (purpose_N % 10) * 10 + ((purpose_N / 10) + (purpose_N % 10)) % 10; /* 10보다 크거나 같을 때 새로운 수 */

    cout << cycle_length (new_N, 1);

    return 0;
}