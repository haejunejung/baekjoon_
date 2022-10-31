#include <iostream>
#include <map>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map <int, int> map1;
    int A, B, val;
    cin >> A >> B;
    size_t count = 0;

    for (int i = 0; i < A; ++i) {
        cin >> val;
        map1.insert({val, 0});
    }

    for (int i = 0; i < B; ++i) {
        cin >> val;

        if (map1.find(val) != map1.end()) {
            count += 2;
        }
    }

    cout << A+B-count << "\n";

    return 0;
}