#include <iostream>

using namespace std;

int N;
bool check[8];
int sequence[8];

void dfs (int count)
{
    if (count == N)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << sequence[i] << " ";
        }  
        cout << "\n";  

        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            sequence[count] = i + 1;
            dfs (count+1);
            check[i] = false;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dfs (0);

    return 0;
}