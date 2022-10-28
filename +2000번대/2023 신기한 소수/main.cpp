#include <iostream>

int N;

bool IsPrime (const int num) {
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0) return false;
    }

    return true;
}

void checkNum (int num, int exp) {
    if (exp == N) {
        std::cout << num << '\n';
        return;
    }

    for (int i = 1; i <= 9; ++i) {
        if (IsPrime(num * 10 + i)) {
            checkNum(num * 10 + i, exp+1);
        }
    }
}

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    checkNum(2,1);
    checkNum(3,1);
    checkNum(5,1);
    checkNum(7,1);
    
    return 0;
}