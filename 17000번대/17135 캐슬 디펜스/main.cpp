#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[16][16];
int Archer[4];
int N,M,D,Res;

int dx[3] = { -1, 0, 1};
int dy[3] = { 0, -1, 0};

void input ()
{
    cin >> N >> M >> D;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
        }
    }
    Res = 0;
}

void solution ()
{
    int mapCopy[16][16];
    int kill = 0;
    int pos = N + 1; /* 궁수 처음 위치읭 y값 */

    bool check[16][16];
    bool visit[16][16];

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            mapCopy[i][j] = board[i][j];
            check[i][j] = false; /* 적 죽인 곳 체크 */
        }
    }

    while (pos > 1) /* 맵이 아닌 궁수가 앞으로 한 칸씩 간다 가정... */
    {
        for (int i = 1; i <= 3; ++i) /* 궁수의 수 만큼 반복 */
        {
            for (int j = 1; j <= N; ++j)
            {
                for (int k = 1; k <= M; ++k)
                {
                    visit[j][k] = false; /* 지나간 곳인지 체크 */
                }
            }

            queue<pair<int,int>> q;
            int initX = Archer[i];
            int initY = pos-1;

            q.push(make_pair(initX, initY));

            while (!q.empty())
            {
                int currentX = q.front().first;
                int currentY = q.front().second;

                q.pop();

                visit[currentY][currentX] = true;

                if (mapCopy[currentY][currentX]) /* 적 발견시 */
                {
                    check[currentY][currentX] = true; /* 적 공격 */
                    break;
                }

                for (int l = 0; l < 3; ++l)
                {
                    int nextX = currentX + dx[l];
                    int nextY = currentY + dy[l];
                    if (nextX >= 1 && nextY >= 1 && nextX <= M && nextY <= N) /* 다음 이동할 장소가 맵 안에 있는지 확인 */
                    {
                        if (abs(Archer[i] - nextX) + abs(pos - nextY) <= D) /* 궁수 사정거리 안에 있는지 확인 */
                        {
                            if (!visit[nextY][nextX]) /* 이미 지나갔던 곳인지 확인 */
                            {
                                q.push(make_pair(nextX, nextY));
                            }
                        }
                    }
                }
            }
        }

        for (int a = 1; a <= N; ++a) /* 적을 죽인 곳 처리 */
        {
            for (int b = 1; b <= M; ++b)
            {
                if (check[a][b])
                    mapCopy[a][b] = 0;
            }
        }

        pos--;
    }

    for (int i = 1; i <= N; ++i) /* 죽인 수 만큼 kill++ */
    {
        for (int j = 1; j <= M; ++j)
        {
            if (check[i][j]) kill++;
        }
    }

    Res = max(Res, kill);
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input ();

    for (int i = 1; i <= M - 2; ++i)
    {
        for (int j = i + 1; j <= M - 1; ++j)
        {
            for (int k = j + 1; k <= M; ++k)
            {
                Archer[1] = i;
                Archer[2] = j;
                Archer[3] = k;
                solution (); 
            }
        }
    }

    cout << Res;
    return 0;
}