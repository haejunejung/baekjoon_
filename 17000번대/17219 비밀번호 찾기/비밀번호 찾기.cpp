#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

void IO();

int main()
{
    IO();

    unordered_map<string, string> um;
    int N, M;
    cin >> N >> M;

    while (N--)
    {
        string site, password;
        cin >> site >> password;

        um.insert(make_pair(site, password));
    }

    while (M--)
    {
        string site;
        cin >> site;

        cout << um[site] << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}