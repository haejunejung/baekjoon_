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

    bool S[21];
    fill_n(S, 21, false);

    int M;
    cin >> M;

    while (M--)
    {
        string op;
        int x;

        cin >> op;

        if (op == "add")
        {
            cin >> x;
            S[x] = true;
        }
        else if (op == "remove")
        {
            cin >> x;
            S[x] = false;
        }
        else if (op == "check")
        {
            cin >> x;
            cout << S[x] << "\n";
        }
        else if (op == "toggle")
        {
            cin >> x;
            if (S[x])
                S[x] = false;
            else
                S[x] = true;
        }
        else if (op == "all")
        {
            for (size_t i = 1; i <= 20; ++i)
                S[i] = true;
        }
        else
        {
            for (size_t i = 1; i <= 20; ++i)
                S[i] = false;
        }
    }
    return 0;
}