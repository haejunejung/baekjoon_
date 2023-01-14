#include <iostream>
#include <cstring>

using namespace std;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    int M, x, bit = 0;
    cin >> M;

    while (M--)
    {
        string op;
        cin >> op;

        if (op == "add")
        {
            cin >> x;
            bit = bit | (1 << (x - 1));
        }
        else if (op == "remove")
        {
            cin >> x;
            bit = bit & (0xfffff & (~(1 << (x - 1))));
        }
        else if (op == "check")
        {
            cin >> x;
            if (bit & (1 << (x - 1)))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (op == "toggle")
        {
            cin >> x;
            if (bit & (1 << (x - 1)))
                bit = bit & (0xfffff & (~(1 << (x - 1))));
            else
                bit = bit | (1 << (x - 1));
        }
        else if (op == "all")
        {
            bit = 0xfffff;
        }
        else
        {
            bit = 0;
        }
    }

    return 0;
}