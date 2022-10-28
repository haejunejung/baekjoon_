#include <iostream>

using namespace std;

#define MAX(a,b) a > b ? a : b

int max_dice (int fd, int sd, int td) {
    int res = MAX(fd, sd);
    res = MAX(res, td);

    return res;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int first_dice, second_dice, third_dice, prize_money;
    cin >> first_dice >> second_dice >> third_dice;

    if (first_dice == second_dice && second_dice == third_dice) prize_money = 10000 + first_dice * 1000;
    else if (first_dice == second_dice) prize_money = 1000 + first_dice * 100;
    else if (second_dice == third_dice) prize_money = 1000 +  second_dice * 100;
    else if (third_dice == first_dice) prize_money = 1000 + third_dice * 100;
    else prize_money = max_dice(first_dice, second_dice, third_dice) * 100;

    cout << prize_money << endl;

    return 0;
}