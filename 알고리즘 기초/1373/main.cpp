#include <iostream>
#include <cstring>

int main (void) {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; /* string으로 받을 경우, 인덱싱을 할 수 있다. */
    cin >> str;

    size_t len = str.length(); /* 받은 수의 길이 */
    if (len % 3 == 1) /* 3개씩 끊어지지 않을 경우, 앞에 1개나 2개가 인 경우를 미리 잘라준다. */
    {
        cout << str[0];
    }
    else if (len % 3 == 2)
    {
        cout << (str[0]-'0') * 2 + (str[1]-'0'); /* ASCII code */
    }

    for (size_t i = len % 3; i < len; i+=3) /* 나머지 3개씩 잘리는 부분을 출력하는 부분 */
    {
        cout << (str[i]-'0') * 4 + (str[i+1]-'0') * 2 + (str[i+2]-'0');
    }

    return 0; /* 올바르게 종료 */
}   