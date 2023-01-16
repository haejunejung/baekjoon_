#include <iostream>
#include <cstring>

using namespace std;

void IO();

bool IsVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
}

void isAcceptable(string word)
{
    /* 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다. */
    bool isVowel = false;
    for (int i = 0; i < word.size(); ++i)
    {
        if (IsVowel(word[i]))
            isVowel = true;
    }

    if (!isVowel)
    {
        cout << "not acceptable.\n";
        return;
    }

    /* 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다. */
    if (word.size() >= 3)
    {
        for (int i = 1; i < word.size() - 1; ++i)
        {
            if (IsVowel(word[i - 1]) == IsVowel(word[i]) && IsVowel(word[i]) == IsVowel(word[i + 1]))
            {
                cout << "not acceptable.\n";
                return;
            }
        }
    }

    /* 3.같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다. */
    if (word.size() >= 2)
    {
        for (int i = 0; i < word.size() - 1; ++i)
        {
            if (word[i] == word[i + 1] && !(word[i] == 'e' || word[i] == 'o'))
            {
                cout << "not acceptable.\n";
                return;
            }
        }
    }

    cout << "acceptable.\n";
}

int main()
{
    IO();

    while (true)
    {
        string word;
        cin >> word;

        if (word == "end")
            break;

        cout << "<" << word << ">"
             << " is ";
        isAcceptable(word);
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}