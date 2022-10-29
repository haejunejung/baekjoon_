#include <iostream>

using namespace std;

int next_number (int num) {
    int sum = num;
    while (true) {
        sum += num % 10;
        num /= 10;
        if (num / 10 == 0) break;
    }

    if (num % 10 != 0) sum += num;

    return sum;
}

void fill_selfnumber (bool selfnumber[]) {
    for (int i = 1; i <= 10000; ++i) {
        if (!selfnumber[i]) {
            int number = i;
            while (number <= 10000) {
                number = next_number(number);
                if (number > 10000) break;
                selfnumber[number] = true;
            }
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool selfnumber[10001] = { };

    /* selfnumber 인지 아닌지 check하는 함수 */
    fill_selfnumber(selfnumber);

    /* selfnumber 출력 */
    for (int i = 1; i <= 10000; ++i) {
        if (!selfnumber[i]) cout << i << "\n";
    }

    return 0;
}