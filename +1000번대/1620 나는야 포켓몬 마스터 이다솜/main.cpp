#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

bool isNumeric (string const &str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map <string, size_t> map1; /* string, index 저장 */
    map <size_t, string> map2; 
    for (size_t idx = 1; idx <= N; ++idx) {
        string str;
        cin >> str;

        map1.insert({str, idx});
        map2.insert({idx, str});
    }

    for (size_t cnt = 1; cnt <= M; ++cnt) {
        string str;
        cin >> str;

        if (isNumeric(str)) {
            cout << map2.find(stoi(str))->second << "\n";
        }
        else {
            cout << map1.find(str)->second << "\n";
        }
    }

    return 0;
}