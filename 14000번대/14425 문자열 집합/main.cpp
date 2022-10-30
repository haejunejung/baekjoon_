#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, res = 0;
    cin >> N >> M;

    map <string, size_t> map1; /* 문자열, 인덱스저장 */
    for (size_t idx = 0; idx < N; ++idx) {
        string str;
        cin >> str;
        map1.insert({str, idx});
    }

    for (size_t cnt = 1; cnt <= M; cnt++) {
        string str;
        cin >> str;

        if (map1.find(str) != map1.end()) res++;
    }

    cout << res;

    return 0;
}