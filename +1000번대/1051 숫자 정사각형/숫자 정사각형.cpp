#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M;
    cin >> N >> M;

    vector<string> v;
    for (int i = 0; i < N; ++i)
    {
        string inp;
        cin >> inp;

        v.push_back(inp);
    }

    int maximum = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = j + 1; k < M; ++k)
            {
                if (v[i][j] == v[i][k])
                {
                    for (int l = i + 1; l < N; ++l)
                    {
                        if (v[i][j] == v[l][j] && v[i][k] == v[l][k] && (l - i) == (k - j)) // (l-i) == (k-j) -> 정사각형
                            maximum = max(maximum, (k - j + 1) * (l - i + 1));
                    }
                }
            }
        }
    }

    cout << maximum;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}