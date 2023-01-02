#include <iostream>
#include <queue>

int main()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;

    int N;
    cin >> N;

    while (true)
    {
        int val;
        cin >> val;

        if (val == -1)
            break;
        else if (val == 0)
            q.pop();
        else
        {
            if (q.size() < N)
                q.push(val);
        }
    }

    if (q.empty())
        cout << "empty";
    else
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }

    return 0;
}