#include <iostream>
#include <cstring>
#include <vector>

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    size_t MAP[1001][1001] = { }; 
    for (size_t i = 1; i <= str2.length(); ++i)
    {
        for (size_t j = 1; j <= str1.length(); ++j)
        {
            if (str2[i-1] == str1[j-1]) /* 문자가 같다면 */
            {
                MAP[i][j] = MAP[i-1][j-1] + 1; /* 대각선 전 + 1 (대각선 전의 경우는 현재 문자가 나오기 전 나올 수 있는 경우의 수의 최댓값) */
            }
            else
            {
                MAP[i][j] = max(MAP[i-1][j], MAP[i][j-1]);
            }
        }
    }

    cout << MAP[str2.length()][str1.length()];
    return 0;
}