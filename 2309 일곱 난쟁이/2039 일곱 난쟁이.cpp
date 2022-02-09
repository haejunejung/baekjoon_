#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[9], sum = 0;

    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    int temp;
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            temp = sum - arr[i] - arr[j];
            if (temp == 100) {
                arr[i] = 0;
                arr[j] = 0;
                break;
            } 
        }
        if (temp == 100) break;
    }

    sort(arr,arr+9);

    for (int i = 2; i < 9; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}