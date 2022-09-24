#include <iostream>

using namespace std;

/* 현재 진행 방향 */
#define moveX 1 /* 가로 */
#define moveY 2 /* 세로 */
#define moveDiag 3 /* 대각선 */

int N, res;
int board[17][17];

void input ()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
        }
    }

    res = 0;
}

void solution (int direction, int y, int x)
{
    if (x < 0 || y < 0 || x > N || y > N) return; /* 벽에 부딪힐 경우 */
    if (board[y][x] == 1) return; /* 현재 있는 곳에 벽이 있을 경우 */
    if (direction == moveDiag) /* 대각선으로 갈 때는 가로 세로 대각선 모두 벽이 있으면 안된다 */
    {
        if (board[y-1][x] == 1 || board[y][x-1] == 1) return;
    }
    if (x == N && y == N) /* (N,N)에 도착하면 res 하나씩 추가 */
    {
        res += 1;
        return;
    }

    if (direction == moveX) /* 현재 방향이 가로 */
    {
        for (int i = 1; i <= 2; ++i)
        {
            if (i == 1) solution(moveDiag, y+1, x+1);
            else solution(moveX, y, x+1);
        }
    }
    else if (direction == moveY) /* 현재 방향이 세로 */
    {
        for (int i = 1; i <= 2; ++i)
        {
            if (i == 1) solution(moveDiag, y+1, x+1);
            else solution(moveY, y+1, x);
        }
    }
    else /* dir == moveDiag*/
    {
        for (int i = 1; i <= 3; ++i)
        {
            if (i == 1) solution(moveDiag, y+1, x+1);
            else if (i == 2) solution(moveX, y, x+1);
            else solution(moveY, y+1, x);
        }
    }

}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input ();
    solution (moveX, 1, 2);

    cout << res;
    return 0;
}