#include <iostream>

#define MAX 11
#define ll long long
#define ll_MAX 0x7fffffffffffffffL
#define ll_MIN (-0x7fffffffffffffffL-1)

using namespace std;

int N;
int operands[MAX], operators[4];
ll maximum, minimum;

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;

    cin >> N;
    for (i=0; i<N; ++i) 
        cin >> operands[i];
    for (i=0; i<4; ++i)     
        cin >> operators[i];

    maximum = ll_MIN;
    minimum = ll_MAX;
}

void expression (int cnt_operands, long long res) {
    if (cnt_operands == N) {
        maximum = max (maximum, res);
        minimum = min (minimum, res);
        return;
    }

    int i;
    for (i=0; i<4; ++i) {
        if (operators[i]) {
            operators[i]--;
            switch (i)
            {
            case 0 : expression(cnt_operands+1, res+operands[cnt_operands]);
                break;
            case 1 : expression(cnt_operands+1, res-operands[cnt_operands]);
                break;
            case 2 : expression(cnt_operands+1, res*operands[cnt_operands]);
                break;
            case 3 : expression(cnt_operands+1, res/operands[cnt_operands]);
                break;
            default:
                break;
            }
            operators[i]++;
        }
    }
}

void solve () {
    expression (1, operands[0]);
    cout << maximum << "\n" << minimum << endl;

}

int main () {
    input ();
    solve ();
    return 0;
}