#include <iostream>

using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0;

    int num[5];
    for (int i = 0; i < 5; ++i) {
        cin >> num[i];
        sum += num[i];
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = i; j >= 1; j--) {
            if (num[j] < num[j-1]) {
                swap(num[j], num[j-1]);
            }
            else break;
        }
    }

    cout << sum / 5 << "\n" << num[2] << endl;
    return 0;
}