#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, i, j;
    cin >> N >> M;

    int A[100][100];
    int B[100][100];

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            cin >> B[i][j];
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}