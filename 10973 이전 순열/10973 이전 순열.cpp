#include <iostream>
#include <algorithm>
#define Max 10001

using namespace std;

bool compare (int x, int y) {
    return x > y;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[Max] = { };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int index = 0;
    for (int i = n - 1; i > 0; --i) {
        if (arr[i] < arr[i-1]) {
            index = i;
            break;
        }
    }

    if (index == 0) {
        cout << -1;
        return 0;
    }

    for (int i = n - 1; i > 0; --i) {
        if (arr[index-1] > arr[i]) {
            swap(arr[index-1], arr[i]);
            break;
        }
    }

    sort(arr+index, arr+n,compare);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }

    return 0;

}

// 7 2 4 3 5 1 6
// 7 2 4 3 1 5 6

