#include <iostream>
#include <tuple>
#include <climits>

using namespace std;

/* input */
int N,M,K; /* input 으로 받을 N, M, K */
int board[51][51]; /* input 받은 배열 */
bool check[51][51]; /* 배열이 지나갔는지 안지나갔는지 check -> 전역 변수로 놓았지만, TrunArr 함수에 놓아도 가능할 것... */
tuple <int,int,int> t[6]; /* r,c,s 저장 */

/* input 제외 필요한 배열들, */
int copyboard[51][51]; /* input 받은 배열 copy */
int order[6]; /* r,c,s 돌리는 순서 */
bool checkorder[6]; /* r,c,s 돌리는 순서를 dfs로 돌릴 때, 이미 쓴 r,c,s인지 확인하는 boolean array */
int dx[4] = {1, 0, -1, 0}; /* 우, 하, 좌, 상 순서 */
int dy[4] = {0, 1, 0, -1};

/* 정답 저장 */
int res; /* 정답 (최소 열의 합) */

void Input ()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    }

    for (int i = 0; i < K; ++i) /* r,c,s 를 tuple로 한 번에 저장하였다 */
    {
        int r,c,s;
        cin >> r >> c >> s;

        t[i] = make_tuple(r,c,s);
    }

    res = INT_MAX; /* 결과값을 min으로 비교할 것이기 때문에, INT_MAX로 초기화하였다 */
}

void Sumrows () /* 돌려진 배열들의 열의 합 중 최소 열의 합을 구하고, res와 비교해서 저장하는 함수 */
{
    int sumrows = INT_MAX; /* 최댓값으로 설정해놓고 시작 (define으로 987654321로 해도 될 것으로 생각) */
    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= M; ++j)
        {
            sum += copyboard[i][j];
        }
        sumrows = min (sum, sumrows);
    }

    res = min (res , sumrows);
}

void TurnArr (int pos) /* 실제 배열을 돌리는 함수 */
{
    if (pos == K) return; /* pos == K는 K번 r,c,s를 비교하면서 배열을 돌렸다는 것 (다 돌렸을 떄) */

    for (int i = 1; i <= N; ++i) /* check 초기화 (r,c,s 순서가 바뀔 때마다 배열 돌리는 순서가 달라지기 때문) */
    {
        for (int j = 1; j <= M; ++j)
        {
            check[i][j] = false;
        }   
    }

    /* 바뀌는 r,c,s를 저장, */
    int r = get<0>(t[order[pos]]);
    int c = get<1>(t[order[pos]]);
    int s = get<2>(t[order[pos]]);

    /* 처음 시작 지점 -> [initfirst][initsecond] */
    int initfirst = r-s;
    int initsecond = c-s;
    int initval = copyboard[initfirst][initsecond];
    check[initfirst][initsecond] = true;

    while (1)
    {
        for (int i = 0; i < 4; ++i) /* 4번 방향 꺾는다. */
        {
            for (int j = 1; j <= 2 * s; ++j) /* 2s번 만큼 해당 방향으로 이동 */
            {
                /* 다음 지점 저장 (해당 방향으로 이동한 곳) */
                int nextfirst = initfirst + dy[i];
                int nextsecond = initsecond + dx[i];
                int nextval = copyboard[nextfirst][nextsecond];
                check[nextfirst][nextsecond] = true;

                /* 이동한 후, 이동한 지점을 다시 저장 && 배열 돌리기 진행 */
                copyboard[nextfirst][nextsecond] = initval;
                initval = nextval;
                initfirst = nextfirst;
                initsecond = nextsecond;
            }
        }

        /* 다음 지점 (대각선 오른쪽 아래) */
        initfirst += 1;
        initsecond += 1;

        if (initfirst < 1 || initfirst > N || initsecond < 1 || initsecond > M) break; /* 이동한 곳이 범위를 벗어나거나, */
        if (check[initfirst][initsecond]) break; /* 이미 지나간 곳일 경우 종료 */

        s -= 1;
        initval = copyboard[initfirst][initsecond];
        check[initfirst][initsecond] = true;
    }

    TurnArr (pos+1); /* 배열 돌리기를 끝낼 때까지 recursion (반복문으로 작성할 수 있으나, 여기서는 그냥 재귀함수로 하였다. 만약 반복문을 돌리고 싶다면, 함수 처음 ~ 끝까지 반복문을 만들어주면 될 것) */
}

void DFS (int pos) /* r,c,s 순서를 정하는 함수 */
{
    if (pos == K)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                copyboard[i][j] = board[i][j];
            }
        }
        TurnArr (0);
        Sumrows ();
        return;
    }

    for (int i = 0; i < K; ++i)
    {
        if (!checkorder[i])
        {
            checkorder[i] = true;
            order[pos] = i;
            DFS (pos+1);
            checkorder[i] = false;
        }
    }
}

void Solution ()
{
    DFS (0);

    cout << res;
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();
    
    return 0;
}