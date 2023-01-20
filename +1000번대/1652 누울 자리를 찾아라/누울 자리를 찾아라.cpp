#include <iostream>
#include <cstring>

using namespace std;

void IO();

int main()
{
    IO();

    int N, x = 0, y = 0;
    cin >> N;

    string room[100];
    for (int i = 0; i < N; ++i)
        cin >> room[i];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N;)
        {
            int cont = 0;
            while (j < N && room[i][j] == '.')
            {
                cont++;
                j++;
            }

            if (cont >= 2)
                x++;

            j++;
        }

        for (int j = 0; j < N;)
        {
            int cont = 0;
            while (j < N && room[j][i] == '.')
            {
                cont++;
                j++;
            }

            if (cont >= 2)
                y++;

            j++;
        }
    }

    cout << x << " " << y;
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}