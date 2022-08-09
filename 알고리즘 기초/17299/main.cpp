#include <iostream>
#include <stack>

int main (void) {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *input = new int[N];
    int count[1000001] = {};

    for (int i = 0; i < N; ++i)
    {
        cin >> input[i];
        count[input[i]]++;
    }

    stack <int> s;
    stack <int> ans;

    for (int i = N-1; i >= 0; i--)
    {
        while (!s.empty() && count[s.top()] <= count[input[i]])
        {
            s.pop();
        }

        if (s.empty()) ans.push(-1);
        else ans.push(s.top());

        s.push(input[i]);
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}