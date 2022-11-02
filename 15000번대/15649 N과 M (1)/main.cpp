#include <iostream>

using namespace std;

bool check[9];

void NandM (int length, const int N, const int M, int sequence[]) {
    if (length == M) {
        for (int i = 0; i < length; ++i) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!check[i]) {
            sequence[length] = i;
            check[i] = true;
            NandM (length+1, N, M, sequence);
            check[i] = false;
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    int sequence[9] = { };
    NandM (0, N, M, sequence);
    
    return 0;
}