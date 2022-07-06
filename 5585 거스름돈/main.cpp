#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int money;
    cin >> money;

    int rest = 1000 - money, count = 0;
    count += rest / 500;
    rest %= 500;

    count += rest / 100;
    rest %= 100;

    count += rest / 50;
    rest %= 50;

    count += rest / 10;
    rest %= 10;

    count += rest / 5;
    rest %= 5;

    count += rest / 1;
    
    cout << count;
    
    return 0;
}