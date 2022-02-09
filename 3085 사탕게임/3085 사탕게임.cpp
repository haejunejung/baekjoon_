#include <iostream>
#include <string>

#define RED     C
#define BLUE    P
#define GREEN   Z
#define YELLOW  Y

using namespace std;

int solution (string str[], int N) {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int temp = 1;
        for (int j = 0; j < N-1; ++j) {
            if (str[i][j] == str[i][j+1]) {
                temp++;
            } else {
                temp = 1;
            }
            ans = max (temp,ans);
        }
    }

    for (int i = 0; i < N; ++i) {
        int temp = 1;
        for (int j = 0; j < N-1; ++j) {
            if (str[j][i] == str[j+1][i]) {
                temp++;
            } else {
                temp = 1;
            }
            ans = max (temp,ans);
        }
    }

    return ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string str[N];
    for (int i = 0; i < N; ++i) {
        cin >> str[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if(str[i][j] != str[i][j+1]) {
                swap(str[i][j],str[i][j+1]);

                ans = max (solution(str,N), ans);

                swap(str[i][j],str[i][j+1]);
            }
        }      
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if(str[j][i] != str[j+1][i]) {
                swap(str[j][i],str[j+1][i]);

                ans = max (solution(str,N), ans);

                swap(str[j][i],str[j+1][i]);
            }
        }
    }

    cout << ans;
    return 0;


}