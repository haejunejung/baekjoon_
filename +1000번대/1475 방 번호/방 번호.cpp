#include <iostream>

using namespace std;

const int Max = 1000000;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    char str[Max];
    cin.getline(str, Max, '\n');

    int count[10] = {};
    for (size_t i = 0; i < Max; ++i)
    {
        if (str[i] == '\0')
            break;
        int val = str[i] - '0';
        if (val == 6 || val == 9)
        {
            if (count[6] > count[9])
                count[9]++;
            else
                count[6]++;
        }
        else
            count[val]++;
    }

    int res = 0;
    for (size_t i = 0; i < 10; ++i)
    {
        res = max(res, count[i]);
    }

    cout << res;

    return 0;
}