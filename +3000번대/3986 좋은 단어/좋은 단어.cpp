// 좋은 단어
// 문제 이해가 어려웠던 문제
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void IO();

int main()
{
    IO();

    int N, count = 0;
    cin >> N;

    while (N--)
    {
        string word;
        cin >> word;

        stack<char> st;
        for (auto val : word)
        {

            if (!st.empty() && st.top() == val)
                st.pop();
            else
                st.push(val);
        }

        if (st.empty())
            count++;
    }
    cout << count;
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}