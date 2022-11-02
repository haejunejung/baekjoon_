/* 맞았지만 조금 더 나은 방법으로 풀 수 있을 것 같다 */
#include <iostream>
#include <climits>

#define MAX 11

using namespace std;

int N;
int val[MAX];
char oper[MAX];
bool check[MAX];
long long maximum, minimum;

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j, cnt=0;
    cin >> N;
    for(i=0; i<N; ++i) {
        cin >> val[i];
    }

    for(i=0; i<4; ++i) {
        int n;
        cin >> n;

        char type;
        if (i == 0) {
            type = '+';
        } else if (i == 1) {
            type = '-';
        } else if (i == 2) {
            type = '*';
        } else {
            type = '/';
        }

        for(j=0; j<n; ++j) {
            oper[cnt++] = type;
        }
    }

    maximum = LONG_MIN;
    minimum = LONG_MAX;
}

void expression (int cnt_val, long long res) {
    if (cnt_val == N) {
        maximum = max (maximum, res);
        minimum = min (minimum, res);
        return;
    }

    int i;
    for (i=0; i<N; ++i) {
        if (!check[i]) {
            check[i] = true;
            switch (oper[i])
            {
            case '+' : expression(cnt_val+1, res+val[cnt_val]);
                break;
            case '-' : expression(cnt_val+1, res-val[cnt_val]);
                break;
            case '*' : expression(cnt_val+1, res*val[cnt_val]);
                break;
            case '/' : expression(cnt_val+1, res/val[cnt_val]);
                break;
            
            default:
                break;
            }
            check[i] = false;
        }
    }
}

void solve () {
    expression (1, val[0]);
    cout << maximum << "\n" << minimum << endl;
}

int main (void) {

    input ();
    solve ();

    return 0;
}