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

    int N, k;
    cin >> N >> k;

    int student[1000];
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        student[i] = x;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (student[i] < student[j]) {
                swap(student[i], student[j]);
            }
        }
    }

    cout << student[k-1] << endl;

    return 0;
}