#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void IO();

bool vec_push(vector<char> &v, int &count)
{
    if (count == 0)
        return true;

    else if (count % 2 == 0)
    {
        for (int i = 0; i < (count / 4) * 4; ++i)
            v.push_back('A');

        count %= 4;

        for (int i = 0; i < count; ++i)
            v.push_back('B');

        count = 0;
        return true;
    }

    else
        return false;
}

int main()
{
    IO();

    string inp;
    cin >> inp;

    vector<char> v;
    int count = 0;

    for (int i = 0; i < inp.size(); ++i)
    {
        if (inp[i] == 'X')
            count++;
        else
        {
            if (vec_push(v, count))
                v.push_back('.');
            else
            {
                cout << -1;
                return 0;
            }
        }
    }

    if (!vec_push(v, count))
    {
        cout << -1;
        return 0;
    }

    for (auto val : v)
        cout << val;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}