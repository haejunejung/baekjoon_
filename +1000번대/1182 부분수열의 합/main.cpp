#include <iostream>
#include <vector>

using namespace std;

int N,S,Res = 0;
int num[20]; /* 숫자 저장 */
bool check[20]; /* 숫자가 이미 수열에 들어가있는지 확인 */
vector <int> v; /* 부분 수열 저장 */

void dfs (int pos, int currentSize, int sequenceSize)
{
    if (currentSize == sequenceSize)
    {
        int sum = 0;
        for (size_t i = 0; i < v.size(); ++i)
        {
            sum += v[i];
        }

        if (sum == S) Res += 1;
        return;
    }

    for (int i = pos; i < N; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            v.push_back(num[i]);
            dfs (i, currentSize+1, sequenceSize);
            check[i] = false;
            v.pop_back();
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> num[i];

    for (int i = 1; i <= N; ++i) /* 수열의 수의 개수 */
    {
        for (int j = 0; j < N; ++j)
            check[j] = false;

        dfs (0, 0, i);
    }

    cout << Res;
    return 0;
}