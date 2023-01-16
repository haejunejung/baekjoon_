#include <iostream>
#include <deque>

using namespace std;

void IO();

int main()
{
    IO();

    deque<int> dq;

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        dq.push_back(i);

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();

        if (dq.empty())
            break;

        dq.push_back(dq.front());
        dq.pop_front();
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}