#include <iostream>

using namespace std;

int N, total; /* N -> queen이 들어가야하는 수, total -> 최종 count */
int check[15]; /* 해당 col에 row를 넣을 수 있는지 확인하는 배열 */

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    total = 0; /* 0으로 초기화 */
}

bool Ispossible (int col) {
    int i;
    for (i=0; i<col; ++i) {
        /* 
            row가 겹치거나 -> check[col] == check[i] 
            대각선에 위치한다면, abs(check[col]-check[i]) == col-i
            넣을 수 없으므로 false 리턴
        */
        if (check[col] == check[i] || abs(check[col]-check[i]) == col-i) return false;
    }
    return true;
}

void NQueen (int col) {
    if (col == N) { /* col == N -> queen이 N개가 되었다 -> total++ */
        total++;
        return;
    }

    int row;
    for (row=0; row<N; ++row) {
        check[col] = row; /* 해당 col에 row를 넣는다 */
        if (Ispossible(col)) NQueen(col+1);
    }
}

void solve () {
    NQueen (0);
    cout << total << endl;
}

int main () {
    input ();
    solve ();

    return 0;
}