#include <iostream>

#define Max 16

using namespace std;

int N, T[Max], P[Max], maximum = 0;

void Initialize () {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }
}

void Consulting (int day, int sum) {
    if (day > N + 1) return;
    else maximum = max (maximum, sum);

    for (int i = day; i <= N; ++i) {
        Consulting (i + T[i], sum + P[i]);
    }
}

void Solution () {
    for (int i = 1; i <= N; ++i) {
        Consulting (i + T[i], P[i]);
    }
}

void Print () {
    cout << maximum;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize ();
    Solution ();
    Print ();
    return 0;
}