#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001

using namespace std;

vector<int> vec;

bool check(int val, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid] > val)
            end = mid - 1;
        else if (vec[mid] < val)
            start = mid + 1;
        else
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, val;
    cin >> N;

    for (size_t i = 1; i <= N; ++i)
    {
        cin >> val;
        vec.push_back(val);
    }

    sort(vec.begin(), vec.end(), [](int &a, int &b)
         { return a < b; });

    cin >> M;
    for (size_t i = 1; i <= M; ++i)
    {
        cin >> val;

        cout << check(val, 0, N - 1) << "\n";
    }

    return 0;
}