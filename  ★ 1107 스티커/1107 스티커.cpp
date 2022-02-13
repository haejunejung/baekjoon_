#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 되는 것만 확인하는거에 초점을 두고 브루드 포스를 이용 .. 

bool broken_channel[10] = { }; // true = broke, false = normal 

bool check_ (int num) {
    string temp = to_string(num);
    for (int i = 0; i < temp.length(); ++i) {
        if (broken_channel[temp[i]-'0'] == true) {
            return false;
        }
    }

    return true;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        broken_channel[num] = true;
    }

    int minimum = abs(N-100);

    for (int i = 0; i < 1000000; ++i) {
        if (check_(i) == true) {
            int temp = abs(N-i) + to_string(i).length();
            minimum = min(minimum, temp);
        }
    }

    cout << minimum;
    return 0;
    

}