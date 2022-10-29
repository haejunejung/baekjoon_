#include <iostream>
#include <cstring>

using namespace std;

int number (char ch) {
    if (ch == 'A' || ch == 'B' || ch == 'C') return 3;
    else if (ch == 'D' || ch == 'E' || ch == 'F') return 4;
    else if (ch == 'G' || ch == 'H' || ch == 'I') return 5;
    else if (ch == 'J' || ch == 'K' || ch == 'L') return 6;
    else if (ch == 'M' || ch == 'N' || ch == 'O') return 7;
    else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S') return 8;
    else if (ch == 'T' || ch == 'U' || ch == 'V') return 9;
    else return 10;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string word; // 할머니가 외운 단어 //
    cin >> word;

    unsigned int sum = 0;
    for (size_t i = 0; i < word.length(); ++i) {
        sum += number(word[i]);
    }

    cout << sum;

    return 0;
}