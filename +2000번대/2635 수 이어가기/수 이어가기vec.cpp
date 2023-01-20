#include <iostream>
#include <vector>

using namespace std;

void IO();

int main()
{
    IO();

    int n, maxCount = 0;
    cin >> n;

    vector<int> result;
    for (int start = 1; start <= n; ++start)
    {
        vector<int> temp;
        int firstNum = n;
        int secondNum = start;

        temp.push_back(firstNum);
        temp.push_back(secondNum);

        while (firstNum >= secondNum)
        {
            int nextNum = firstNum - secondNum;
            firstNum = secondNum;
            secondNum = nextNum;

            temp.push_back(nextNum);
        }

        if (maxCount < temp.size())
        {
            result = temp;
            maxCount = result.size();
        }
    }

    cout << result.size() << "\n";

    for (auto val : result)
        cout << val << " ";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}