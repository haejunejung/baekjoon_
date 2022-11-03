#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int board[9][9];
vector <pair<int,int>> blank;

bool check (int first, int second) {
    int i,j;
    for(i=0; i<9; ++i) {
        if (i == second) continue;
        if (board[first][i] == board[first][second]) return false;
    }

    for(i=0; i<9; ++i) {
        if (i == first) continue;
        if (board[i][second] == board[first][second]) return false;
    }

    int square_first = first / 3;
    int square_second = second / 3;
    for(i=3*square_first; i<3*square_first+3; ++i) {
        for(j=3*square_second; j<3*square_second+3; ++j) {
            if (i == first && j == second) continue;
            if (board[i][j] == board[first][second]) return false;
        }
    }

    return true;
}

void sudoku (size_t fill) {
    int i,j;
    if (fill == blank.size()) {
        for(i=0; i<9; ++i) {
            for(j=0; j<9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        exit(0);
    }

    int first = blank[fill].first;
    int second = blank[fill].second;
    for(i=1; i<=9; ++i) {

        board[first][second] = i;
        if (check(first, second)) {
            sudoku(fill+1);
        }
    }
    board[first][second] = 0;
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j,val;
    for(i=0; i<9; ++i) {
        for(j=0; j<9; ++j) {
            cin >> val;
            board[i][j] = val;

            if (!val) blank.push_back(make_pair(i,j));
        }
    }

    sudoku(0);
    return 0;
}