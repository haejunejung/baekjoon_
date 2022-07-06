#include <iostream>
#include <algorithm>
#include <cstring>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    bool flag = false;
    int sum = 0;
    int *arr = new int[input.size()];
    for (int i = 0; i < input.size(); ++i) {
        arr[i] = input[i] - '0';
        sum += arr[i];
        if (arr[i] == 0) flag = true;
    }

    if (sum % 3 !=0 || flag == false) {
        cout << -1;
        return 0;
    }

    sort(arr, arr+input.size(), greater<>());

    for (int i = 0; i < input.size(); ++i) {
        cout << arr[i];
    }



    return 0;
}