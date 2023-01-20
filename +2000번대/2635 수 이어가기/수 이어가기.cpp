#include <iostream>

using namespace std;

void IO();

int makeCount(int firstNum, int secondNum)
{
    int count = 0;
    while (firstNum >= secondNum)
    {
        int temp = firstNum - secondNum;
        firstNum = secondNum;
        secondNum = temp;
        count++;
    }

    return count + 2;
}

void res(int firstNum, int secondNum)
{
    cout << firstNum << " " << secondNum << " ";
    while (firstNum >= secondNum)
    {
        int temp = firstNum - secondNum;
        firstNum = secondNum;
        secondNum = temp;

        cout << temp << " ";
    }
}

int main()
{
    IO();

    int n, maxCount = 0, maxNumber = 0;
    cin >> n;

    for (int i = n / 2; i <= n; ++i)
    {
        if (maxCount < makeCount(n, i))
        {
            maxCount = makeCount(n, i);
            maxNumber = i;
        }
    }

    cout << maxCount << "\n";
    res(n, maxNumber);

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}