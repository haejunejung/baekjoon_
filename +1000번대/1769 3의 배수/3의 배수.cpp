#include <iostream>
#include <cstring>

using namespace std;

void IO();

int addEachElement(int X)
{
    int sum = 0;
    while (X > 0)
    {
        sum += (X % 10);
        X /= 10;
    }

    return sum;
}

int main()
{
    IO();

    string X;
    cin >> X;

    int count = 1, sum = 0;
    bool flag;

    if (X.size() == 1)
        flag = false;
    else
        flag = true;

    for (auto val : X)
        sum += (val - '0');

    while (sum > 9)
    {
        sum = addEachElement(sum);
        count++;
    }

    count = (flag) ? count : 0;
    cout << count << "\n";

    if (sum % 3 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}