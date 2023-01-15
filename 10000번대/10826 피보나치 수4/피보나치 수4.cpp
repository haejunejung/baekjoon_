#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void IO();

int main()
{
    IO();

    int n;
    cin >> n;

    if (n == 0)
        cout << 0;
    else if (n == 1 || n == 2)
        cout << 1;
    else
    {
        string prev = "1", current = "1", next = "2";
        for (int i = 3; i < n; ++i)
        {
            prev = current;
            current = next;

            int quo = 0, rem = 0;
            string temp;
            for (int i = 0; i < prev.size(); ++i)
            {
                int sum = (prev[i] - '0') + (current[i] - '0') + quo;
                quo = sum / 10;
                rem = sum % 10;

                temp += (rem + '0');
            }

            for (int i = prev.size(); i < current.size(); ++i)
            {
                int sum = (current[i] - '0') + quo;
                quo = sum / 10;
                rem = sum % 10;

                temp += (rem + '0');
            }

            if (quo > 0)
                temp += (quo + '0');

            next = temp;
        }

        reverse(next.begin(), next.end());
        cout << next;
    }
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}