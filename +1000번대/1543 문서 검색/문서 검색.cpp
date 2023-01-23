#include <iostream>
#include <cstring>

using namespace std;

void IO();

bool isEqual(string document, string word, int start)
{
    for (int i = start; i < start + word.size(); ++i)
    {
        if (document[i] == word[i - start])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    IO();

    string document, word;

    getline(cin, document);
    getline(cin, word);

    int count = 0;
    for (int i = 0; i < document.size();)
    {
        if (i + word.size() > document.size())
            break;

        string docWord;
        for (int j = i; j < i + word.size(); ++j)
        {
            docWord += document[j];
        }

        if (docWord == word)
        {
            count++;
            i += word.size();
        }
        else
            i++;
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