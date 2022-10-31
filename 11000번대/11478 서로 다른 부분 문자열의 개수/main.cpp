#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map <string, int> map1;
    string S;
    cin >> S;

    size_t len = S.length();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < len-i; ++j) {
            string temp = S.substr(i, j+1); /* S의 substr을 모두 저장 */
            map1.insert({temp, 0}); /* map의 특성상 중복되면 저장안함 */
        }
    }

    cout << map1.size() << "\n"; /* 중복이 없기 때문에 size -> 답이 됨 */

    return 0;
}