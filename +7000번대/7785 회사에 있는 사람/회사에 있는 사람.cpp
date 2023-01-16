#include <iostream>
#include <map>
#include <cstring>

using namespace std;

void IO();

int main()
{
    IO();

    int n;
    cin >> n;

    map<string, bool, greater<>> m;

    for (int i = 0; i < n; ++i)
    {
        string name, op;
        cin >> name >> op;

        if (op == "enter")
            m.insert({name, true});
        else
            m.erase(m.find(name));
    }

    for (auto val : m)
        cout << val.first << "\n";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}