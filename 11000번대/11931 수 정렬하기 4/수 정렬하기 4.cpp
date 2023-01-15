#include <iostream>

using namespace std;

void IO();

const unsigned int MAX = 1000000;

int arr[MAX];

void merge(int left, int right)
{
    int temp_arr[MAX];
    int mid = (left + right) / 2;

    int ll = left;
    int rr = mid + 1;
    int idx = left;

    while (ll <= mid && rr <= right)
    {
        if (arr[ll] < arr[rr])
            temp_arr[idx++] = arr[rr++];
        else
            temp_arr[idx++] = arr[ll++];
    }

    while (ll <= mid)
    {
        temp_arr[idx++] = arr[ll++];
    }

    while (rr <= right)
    {
        temp_arr[idx++] = arr[rr++];
    }

    for (int i = left; i <= right; ++i)
        arr[i] = temp_arr[i];
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right);
    }
}

int main()
{
    IO();

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    merge_sort(0, N - 1);

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}