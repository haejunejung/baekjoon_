#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (int &a, int &b) {
    return a < b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector <int> grade;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        grade.push_back(num);
    }

    sort (grade.begin(), grade.end());

    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += abs(i - grade[i-1]);
    }

    cout << sum;
    return 0;
}