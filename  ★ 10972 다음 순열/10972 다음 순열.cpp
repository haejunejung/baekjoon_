#include <iostream>
#include <algorithm>

#define Max 10001

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[Max] = { };

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int idx = 0;
    for (int i = n-1; i > 0; --i) {
        if (arr[i] > arr[i-1]) {
            idx = i;
            break;
        }
    }

    if (idx == 0) {
        cout << -1;
        return 0;
    }

   for (int i = n-1; i >= idx; --i) {
       if (arr[idx-1] < arr[i]) {
           swap(arr[idx-1], arr[i]);
           break;
       }
   }

   sort(arr+idx, arr+n);

   for (int i = 0; i < n; ++i) {
       cout << arr[i] << ' ';
   }

    return 0;
}

// recursive로 풀면 시간 초과.. 
// 1 2 3 4 -> 1 2 4 3

// 1 3 2 4 -> 1 3 4 2

// 1 3 4 2 -> 1 4 2 3

// 1 4 2 3 -> 1 4 3 2


