#include <iostream>
#include <queue>

using namespace std;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    int N;
    cin >> N;

    priority_queue<int> pq;

    for (int i = 0; i < N; ++i)
    {
        int inp;
        cin >> inp;

        if (inp == 0 && !pq.empty())
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (inp == 0 && pq.empty())
        {
            cout << 0 << "\n";
        }
        else
            pq.push(inp);
    }

    return 0;
}