#include <iostream>

#define inf 100000000;
#define Max 21

using namespace std;

int difference = inf;
int N, S[Max][Max];
bool check[Max];

void Solution (int cnt, int pos) {
    if (cnt == N/2) {
        int start = 0 , link = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (check[i] == true && check[j] == true) start += S[i][j];

                if (check[i] == false && check[j] == false) link += S[i][j];
            }
        }

        int temp = abs(start - link);
        if (temp < difference) difference = temp;

        return;
    }

    for (int i = pos; i < N; ++i) {
            check[i] = true;
            Solution (cnt + 1, i + 1);
            check[i] = false;
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> S[i][j];
        }
    }

    Solution (0, 1);
    cout << difference;
    return 0;
}