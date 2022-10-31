#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <map>

using namespace std;

bool compare (const string &s1, const string &s2) {
    return s1 < s2;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map <string, int> map1;
    list <string> li;
    int N, M;
    string val;
    size_t count = 0;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> val;
        map1.insert({val, i});
    }

    for (int j = 0; j < M; ++j) {
        cin >> val;
        if (map1.find(val) != map1.end()) {
            count++;
            li.push_back(val);
        }
    }

    li.sort();

    cout << count << "\n";
    for (auto iter : li) {
        cout << iter.data() << "\n";
    }

    return 0;
}