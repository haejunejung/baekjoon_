#include <iostream>
#include <cstring>

using namespace std;

int N, res;
string current, future;

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> current >> future;
    res = 987654321; /* 큰 수로 체크하여 min으로 비교할 것임 */
}

char changeState (char ch) {
    if (ch == '0') return '1';
    else return '0';
}

void switchbulb (bool IsSwitchFirst) {
    string copy_current = current;
    int count = 0;
    if (IsSwitchFirst == true) {
        copy_current[0] = changeState(copy_current[0]);
        copy_current[1] = changeState(copy_current[1]);
        count++;
    }

    for (int i = 1; i < N-1; ++i) {
        if (copy_current[i-1] != future[i-1]) {
            copy_current[i-1] = changeState(copy_current[i-1]);
            copy_current[i] = changeState(copy_current[i]);
            copy_current[i+1] = changeState(copy_current[i+1]);
            count++;
        }
    }

    if (copy_current[N-2] != future[N-2]) {
        copy_current[N-2] = changeState(copy_current[N-2]);
        copy_current[N-1] = changeState(copy_current[N-1]);
        count++;
    }


    if(copy_current == future) res = min(res, count);
}

void solution () {
    switchbulb (true);
    switchbulb (false);
    if (res == 987654321) cout << -1;
    else cout << res;
}

int main () {
    input ();
    solution ();
    return 0;
}