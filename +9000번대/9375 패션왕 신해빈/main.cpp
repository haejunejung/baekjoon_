#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; testcase++) {
        size_t n,i;
        cin >> n;

        /* map을 사용한 이유 -> 중복된 값을 저장안하면서 횟수를 value로 저장할 수 있다*/
        map <string, size_t> map1; 

        for (i=0; i<n; ++i) {
            string d, t;
            cin >> d >> t;

            if (map1.find(t) != map1.end()) {
                /* 이미 저장된 type이면, 해당 type이 나온 횟수 + 1 */
                map1.find(t)->second += 1;
            }
            else {
                /* 저장되어있지 않다면, type이 나온 횟수 = 1 */
                map1.insert({t, 1});
            }
        }

        /* 
            (해당 타입이 나오는 경우의 수 + 한 번도 안나올 경우의 수)를 각각 곱하고 
            모든 타입이 한 번도 안나오는 경우의 수 1을 빼준다
         */
        size_t res = 1;
        for (auto iter : map1) {
            res *= (iter.second+1);
        }

        cout << res-1 << "\n";
    }

    return 0;
}