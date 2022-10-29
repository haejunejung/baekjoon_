#include <iostream>

using namespace std;

int N, K, cnt;
int A[500000]; /* 정수 저장할 배열 A */
int temp[500000]; /* merge에 사용되는 배열 temp */

int count () { /* 몇 번째 저장되는지 count하는 함수 */
    cnt++;
    return cnt;
}

void merge (int left, int right) {
    int mid = (left + right) / 2;

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) temp[k++] = A[i++];
        else temp[k++] = A[j++];
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (int i = left; i <= right; ++i) {
        A[i] = temp[i];
        if (K == count()) cout << A[i]; /* K와 저장되는 횟수가 같다면, 저장되는 수 출력 */
    }
}

void partition (int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        partition(left, mid);
        partition(mid+1, right);
        merge(left, right);
    }
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) 
        cin >> A[i];
    cnt = 0;
}

int main (void) {
    input ();
    partition(0, N-1);

    if (K >= count()) cout << -1 << "\n"; /* 저장되는 수가 없다면 (K보다 저장되는 회수가 적다면), -1 출력 */

    return 0;
}