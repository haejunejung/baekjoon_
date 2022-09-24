#include <iostream>
#include <string>
#define zero    "000"
#define one     "001"
#define two     "010"
#define three   "011"
#define four    "100"
#define five    "101"
#define six     "110"
#define seven   "111"

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    if (str == "0") {
        cout << '0';
        return 0;
    }


    string ans;
    for (int i = 0; i < str.size(); ++i) {
        int n = str[i] - '0';
        switch (n)
        {
        case 0 : ans += zero;
            break;
        case 1 : ans += one;
            break;
        case 2 : ans += two;
            break;
        case 3 : ans += three;
            break;
        case 4 : ans += four;
            break;
        case 5 : ans += five;
            break;
        case 6 : ans += six;
            break;
        case 7 : ans += seven;
            break;    
        
        default:
            break;
        }
    }

    while (true) {
        if (*ans.begin() == '0') ans.erase(ans.begin());
        else break;
    }

    cout << ans;
    return 0;
}