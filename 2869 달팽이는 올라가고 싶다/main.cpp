#include <iostream>

int main () {
    using namespace std;
    unsigned int A, B, V;
    cin >> A >> B >> V;

    unsigned int day;

    if((V-A) % (A-B) == 0) day = (V-A)/(A-B);
    else day = (V-A)/(A-B) + 1;

    cout << day+1;


    return 0;
}