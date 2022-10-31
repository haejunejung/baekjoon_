#include <iostream>
#include <cmath>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int R;
    cin >> R;

    double EuclideanCircle = M_PI * R * R;
    double TaxiCircle = 2 * R * R;

    cout << fixed;
    cout.precision(6);
    cout << EuclideanCircle << "\n" << TaxiCircle << "\n";

    return 0;
}