/*
    1. Copy board
    2. 각 모서리에 도착하면, 방향 회전
    3. Check가 된 곳을 갔다면 (처음 지점으로 갔다면) 대각선 오른쪽 밑으로 간다.
    4. 배열의 유효 공간을 넘어가거나, check가 되어 있다면 (이미 지나간 곳) 이라면, 배열 돌리기 종료
    5. 다음 배열 돌리기 진행 -> 모든 배열 돌리기 끝나면,
    6. 행 별로 더해서 최솟값 출력

    1) Recursion version
    2) No Recursion version (Just Using for, while)

    - 이 파일은 NO Recursion version -

    첫 번째 시도 -> 틀린 이유) 배열 돌리기를 순서대로 진행 후 행을 더하는 것으로 이해했는데, 알고보니 배열을 돌리는 순서도 정해서 그 안에서 행이 최소가 될 때를 구하는 것이었다. 
*/
#include <iostream>
#include <climits>

using namespace std;

int N, M, K;
int board[51][51];
bool check[51][51];
int dx[4] = {1, 0, -1, 0}; /* 상 하 좌 우 */
int dy[4] = {0, 1, 0, -1};

void input ()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    }
}

void SumRows ()
{
    int res = INT_MAX;
    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= M; ++j)
        {
            sum += board[i][j];
        }

        res = min (res, sum);
    }

    cout << res;
}

void TurnArr (int r, int c, int s)
{
    int initFirst = r-s;
    int initSecond = c-s;
    int initNum = board[r-s][c-s];
    check[r-s][c-s] = true;

    while (1) /* 다음 대각선으로 이동 */
    {
        for (int i = 0; i < 4; ++i) /* 방향 전환 */
        {
            for (int j = 1; j <= 2 * s; ++j) /* s 개수만큼 이동 */
            {
                int nextFirst = initFirst + dy[i]; /* 이동 방향으로 first, second 이동 */
                int nextSecond = initSecond + dx[i];
                int nextNum = board[nextFirst][nextSecond]; /* 이동 방향에 있는 수 저장 */

                board[nextFirst][nextSecond] = initNum; /* 배열 돌리기 */
                initNum = nextNum; /* 다음에 돌리기 위해 수 이동 */
                check[nextFirst][nextSecond] = true; /* 해당 지역을 지났다고 check */

                initFirst = nextFirst; /* 현재의 다음 수는, 이후의 현재 수가 되므로 first, second 교체 */
                initSecond = nextSecond;
            }
        }

        initFirst += 1; /* 대각선 이동 (배열 돌리는 부분 전부 거쳐가야함) */
        initSecond += 1;
        s -= 1; /* 이동하는 횟수 조절 */

        if (initFirst < 1 || initFirst > N || initSecond < 1 || initSecond > M) break; /* 배열 밖으로 벗어나면 종료 */
        if (check[initFirst][initSecond]) break; /* 이미 지나갔던 곳이면 종료 (모든 배열 돌리기 끝) */

        initNum = board[initFirst][initSecond]; /* 다음 대각선의 수를 처음 수로 저장 */
        check[initFirst][initSecond] = true; /* 다음 대각선을 지난 것으로 시작 */
    }

    return;
}

void solution ()
{
    for (int k = 1; k = K; ++k)
    {
        for (int i = 1; i <= N; ++i) /* check 초기화 */
        {
            for (int j = 1; j <= M; ++j)
                check[i][j] = false;
        }

        int r, c, s; /* 회전 연산 정보 */
        cin >> r >> c >> s;
        TurnArr (r,c,s); /* 배열 돌리기 */
    }

    SumRows (); /* */
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input ();
    solution ();

    return 0;
}