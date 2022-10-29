#include <iostream>
#include <cstring>

using namespace std;

bool IsGroupWord (string word) {
    int checkAlphabet[128] = { }; /* ASCII CODE로 저장할 것으로 128개로 만들었다 */

    size_t idx = 0, length = word.length();
    while (idx < length) {
        char currentAlphabet = word[idx++]; /* 현재 알파벳 */
        if (checkAlphabet[int(currentAlphabet)]) return false; /* 이미 한 번 왔었던 알파벳이면 그룹 단어가 아니다 */
        checkAlphabet[int(currentAlphabet)]++; /* 한 번도 안 온 알파벳 -> 방문한 알파벳 */
        while (idx < length) { /* 동일한 알파벳이 안올 때까지 idx++ */
            if (word[idx] != currentAlphabet) break;
            idx++;
        }
    }

    return true;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase, count = 0;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase) {
        string word;
        cin >> word;

        bool flag = IsGroupWord (word);
        if (flag) count++;
    }

    cout << count;

    return 0;
}