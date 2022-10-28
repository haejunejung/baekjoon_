#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, countBook;
vector <int> pos, neg;

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    countBook = 0;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (num > 0) pos.push_back(num);
        else if (num == 0) continue;
        else neg.push_back(num);
    }

    sort (pos.begin(), pos.end(), greater<>()); /* 큰 것부터 내림차순 */
    sort (neg.begin(), neg.end(), less<>()); /* 작은 것부터 오름차순 */
}

void solution () {
    int move = 0;
    int posSize = pos.size();
    int negSize = neg.size();
    int starti = 0, stratj = 0, i,j;

    if (posSize == 0) {
        move += abs(neg[0]);
        stratj += M;

        for (j = stratj; j < negSize-M; j+=M) {
            move += abs(neg[j]) * 2;
        }
        if (negSize-1 >= j) move += abs(neg[j]) * 2;
    }

    else if (negSize == 0) {
        move += pos[0];
        starti += M;

        for (i = starti; i < posSize-M; i+=M) {
            move += pos[i] * 2;
        }
        if (posSize-1 >= i) move += pos[i] * 2;
    }
    
    else {
        if (pos[0] > abs(neg[0])) {
        // cout << pos[0] << " ";
            move += pos[0];
            starti += M;
        }
        else {
            // cout << neg[0] << " ";
            move += abs(neg[0]);
            stratj += M;
        }

        for (i = starti; i < posSize-M; i+=M) {
            // cout << pos[i] << " ";
            move += pos[i] * 2;
        }
        if (posSize-1 >= i) {
            // cout << pos[i] << " ";
            move += pos[i] * 2;
        }

        for (j = stratj; j < negSize-M; j+=M) {
            // cout << neg[j] << " ";
            move += abs(neg[j]) * 2;
        } 
        if (negSize-1 >= j) {
            // cout << neg[j] << " ";
            move += abs(neg[j]) * 2;
        }
    }

    cout << move;
}

// 22 + 39 + 58 + 12 // 

int main () {
    input ();
    solution ();
    return 0;
}