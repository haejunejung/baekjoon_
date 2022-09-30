#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int one_Num = 0, zero_Num = 0;
    cin >> n;

    long long score = 0;
    vector <long long> plusV;
    vector <long long> minusV;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num == 1) one_Num++;
        else if (num == 0) zero_Num++;
        else if (num > 1) plusV.push_back(num);
        else minusV.push_back(num);
    }

    sort (plusV.begin(), plusV.end(), greater<>());
    sort (minusV.begin(), minusV.end());

    /* 이 부분을 안넣으면 outofBound가 뜨는데 왜 그러는지 모르겠다 */
    int plusSize = plusV.size();
    int minusSize = minusV.size();

    for (int i = 0; i < minusSize - 1; i += 2) {
        score += minusV[i] * minusV[i+1];
    }

    if (minusV.size() % 2 == 1 && !zero_Num) score += minusV.back();

    for (int i = 0; i < plusSize - 1; i += 2) {
        score += plusV[i] * plusV[i+1];
    }

    if (plusV.size() % 2 == 1) score += plusV.back();
    score += one_Num;

    cout << score;
    return 0;
}