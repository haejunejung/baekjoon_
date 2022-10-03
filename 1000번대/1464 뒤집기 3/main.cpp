#include <iostream>
#include <cstring>

using namespace std;

string S;

void swap (int i, int j) {
    char ch = S[i];
    S[i] = S[j];
    S[j] = ch;
}

void reverse (int end) {
    for (int i = 0; i <= end/2; ++i) {
        swap(i, end-i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S;

    size_t length = S.size();

    for (int i = 0; i < length-1; ++i) {
        if (S[i] < S[i+1]) {
            reverse(i);
            reverse(i+1);
        }
    }

    reverse(length-1);
    cout << S;
    return 0;
}