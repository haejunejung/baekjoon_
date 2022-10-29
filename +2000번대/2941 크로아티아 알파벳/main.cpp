#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string word;
    cin >> word;

    size_t idx = 0, count = 0;
    size_t length = word.length();
    while (idx < length) {
        if ((word[idx] == 'c') && (idx+1 < length) && (word[idx+1] == '=' || word[idx+1] == '-')) idx += 1;
        else if (word[idx] == 'd') {
            if ((idx+1 < length) && word[idx+1] == '-') idx += 1;
            else if ((idx+2 < length) && word[idx+1] == 'z' && word[idx+2] == '=') idx += 2;
        } 
        else if (word[idx] == 'l' && idx+1 < length && word[idx+1] == 'j') idx += 1;
        else if (word[idx] == 'n' && idx+1 < length && word[idx+1] == 'j') idx += 1;
        else if (word[idx] == 's' && idx+1 < length && word[idx+1] == '=') idx += 1;
        else if (word[idx] == 'z' && idx+1 < length && word[idx+1] == '=') idx += 1;

        count += 1;
        idx += 1;
    }

    cout << count;

    return 0;
}