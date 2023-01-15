#include <iostream>
#include <algorithm>

using namespace std;

void IO();

const unsigned int MAX = 1000000;

int arr[MAX];

int main()
{
    IO();

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N, [](int &a, int &b)
         { return a > b; });

    for (int i = 0; i < N; ++i)
        cout << arr[i] << "\n";
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}