#include <iostream>
#include <algorithm>

#define Max 15

using namespace std;

int L, C;
char arr[Max], ans[Max];
bool check[Max], vowel[Max], consonant[Max];

void Initialize () {
    cin >> L >> C ;

    for (int i = 0; i < C; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+C);
}

void DFS (int cnt, int pos) {
    if (cnt == L) {
        bool flag = false;
        int cnt_vowel = 0 , cnt_consonant = 0;
        for (int i = 0; i < L; ++i) {
            if (vowel[i] == true) cnt_vowel++;
            if (consonant[i] == true) cnt_consonant++;
        }

        if (cnt_vowel >= 1 && cnt_consonant >= 2) {
            for (int i = 0; i < L; ++i) {
                cout << ans[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = pos; i < C; ++i) {
        if (check[cnt] == false) {
            bool flag_ = false;
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') flag_ = true;
            else flag_ = false;

            if (flag_ == true) vowel[cnt] = true;
            else consonant[cnt] = true;

            check[cnt] = true;
            ans[cnt] = arr[i];
            DFS (cnt+1, i+1);

            if (flag_ == true) vowel[cnt] = false;
            else consonant[cnt] = false;
            check[cnt] = false;
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize ();
    DFS (0,0);

    return 0;
}