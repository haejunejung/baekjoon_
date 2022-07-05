#include <iostream>
#include <climits>
#include <vector>

/* 성공 코드 1 */
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        int *price = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> price[i];
        }

        long long sum = 0;
        int max_price = price[N-1];
        for (int i = N-2; i >= 0; --i) {
            if (max_price < price[i]) max_price = price[i];
            sum += max_price-price[i];
        }

        cout << sum << '\n';
    }

    return 0;
}

/* 성공 코드 2 */
int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<int> price;
        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;

            price.push_back(a);
        }

        long long sum = 0, max_price = INT_MIN;
        for (int i = 0; i < N; ++i) {
            if (price.back() > max_price) max_price = price.back();
            sum += max_price - price.back();
            price.pop_back();
        }

        cout << sum << '\n';
    }

    return 0;
}

/* 
실패 코드 -> 현재 시점 이후 가장 큰 수가 아니라
            현재 시점 이후 비싸게 나올 때 파는 것이 되어버려서 틀림
*/
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        int *price = new int[N];
        for (int j = 0; j < N; ++j) {
            cin >> price[j];
        }

        long long sum = 0, partial_sum = 0;
        int count = 0;
        for (int j = 0; j < N-1; ++j) {
            if (price[j] < price[j+1]) {
                partial_sum += price[j];
                count++;
            }

            else if (price[j] > price[j+1]) {
                sum += price[j] * count - partial_sum;
                partial_sum = 0;
                count = 0;
            }
        }

        if (partial_sum != 0 && count != 0) {
            sum += price[N-1] * count - partial_sum;
        }

        cout << sum << '\n';
    }
    
    return 0;
}