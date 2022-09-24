#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long *input = new long long[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> input[i];
    }

    stack <long long> s;
    vector <long long> v;
    pair <long long, size_t> *check = new pair <long long, size_t>[N];
    size_t length = 0;

    v.push_back(input[0]);
    check[0] = {input[0], 0};

    for (int i = 1; i < N; ++i)
    {
        if (v.back() < input[i])
        {
            v.push_back(input[i]);
            length++;
            check[i] = { input[i], length };
        }
        else
        {
            size_t it = lower_bound(v.begin(), v.end(), input[i]) - v.begin();
            v[it] = input[i];
            check[i] = { input[i], it };
        }
    }

    cout << length + 1 << "\n";
    for (int i = N-1; i >= 0; --i)
    {
        if (check[i].second == length)
        {
            s.push(check[i].first);
            length--;
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}