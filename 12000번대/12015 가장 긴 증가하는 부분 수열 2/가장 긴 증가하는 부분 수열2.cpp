#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int N;

void solve()
{
    vector<int> result;
    result.push_back(arr[0]);

    for (int i = 1; i < N; ++i)
    {
        if (result.back() < arr[i])
            result.push_back(arr[i]);
        else
        {
            auto it = lower_bound(result.begin(), result.end(), arr[i]);
            *it = arr[i];
        }
    }

    cout << result.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int inp;
        cin >> inp;

        arr.push_back(inp);
    }

    solve();

    return 0;
}