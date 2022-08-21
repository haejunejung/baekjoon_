#include <iostream>
#include <cstring>

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    if (str.length() == 1 && str[0] == '0'){
        cout << 0;
        return 0;
    }

    int num = str[0] - '0';
    switch (num)
    {
        case 0: cout << "0";
            break;
        case 1: cout << "1";
            break;
        case 2: cout << "10";
            break;
        case 3: cout << "11";
            break;
        case 4: cout << "100";
            break;
        case 5: cout << "101";
            break;
        case 6: cout << "110";
            break;
        case 7: cout << "111";
        default:
            break;
        }

    for (size_t i = 1; i < str.length(); i++)
    {
        num = str[i]-'0';
        switch (num)
        {
        case 0: cout << "000";
            break;
        case 1: cout << "001";
            break;
        case 2: cout << "010";
            break;
        case 3: cout << "011";
            break;
        case 4: cout << "100";
            break;
        case 5: cout << "101";
            break;
        case 6: cout << "110";
            break;
        case 7: cout << "111";
        default:
            break;
        }
    }

    return 0;
    
}