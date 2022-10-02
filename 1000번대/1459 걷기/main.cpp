/*
    시간을 줄이기 위해서 도착점 - 시작점으로 계산할 수 있지만, 
    반복문으로도 돌아가서 하지 않았음.
    시간을 줄이고 싶다면, 계산을 통해 도착점 바로 직전의 지점까지 한 번에 가고,
    그 다음에 움직이는 것도 가능함.
*/
#include <iostream>

using namespace std;

long long X,Y;
int W,S;

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y >> W >> S;
}

void solution () {
    long long x = 0, y = 0, time = 0;
    while (1) {
        if (x == X && y == Y) break;

        if (x == X) { 
            if (y+1 == Y) {
                y += 1;
                time += W;
            }
            else {
                if (W > S) {
                    y += 2;
                    time += 2*S;
                }
                else {
                    y += 2;
                    time += 2*W;
                }
            }
        }

        else if (y == Y) {
            if (x+1 == X) {
                x += 1;
                time += W;
            }
            else {
                if (W > S) {
                    x += 2;
                    time += 2*S;
                }
                else {
                    x += 2;
                    time += 2*W;
                }
            }
        }

        else {
            if (2*W > S) {
                x += 1;
                y += 1;
                time += S;
            }
            else {
                x += 1;
                y += 1;
                time += 2*W;
            }
        }
    }

    cout << time;
}

int main (void) {
    input ();
    solution ();    
    return 0;
}