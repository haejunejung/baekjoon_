/* 
    틀렸던 부분은 make_pair(A,B) 로 함수의 pair된 A,B를 받을 수 있을 것이라 생각했는데 안됐다..
    23%에서 계속 틀렸는데, 사과를 먹으면 보드판 위치에서 사과가 없어져야하는데 없애지 않아서 틀렸다
*/
#include <iostream>
#include <utility>
#include <deque>

using namespace std;

#define apple 1

/* 현재 진행 방향 */
#define left 1
#define right 2
#define up 3
#define down 4

int N, K, L, dir;
int board[102][102];
pair <int, char> information[101]; /* 뱀의 방향 변환 정보 */
deque < pair<int,int> > dq; /* 뱀의 몸통과 머리가 존재하는 곳을 확인 */

void Input ()
{
    cin >> N >> K; /* 보드의 크기, 사과의 개수 */
    for (int i = 1; i <= K; ++i) /* 보드 판에 사과 넣기 */
    {
        int a,b;
        cin >> a >> b;
        board[a][b] = apple;
    }
    cin >> L;
    for (int i = 0; i < L; ++i) /* 정보 배열에 방향 전환 정보 넣기 */
    {
        int X;
        char direction;

        cin >> X >> direction;
        information[i] = make_pair(X, direction);
    }
    dir = right; /* 현재 진행 방향 */

    dq.push_back(make_pair(1,1)); /* 시작 지점 넣어두기 */
}

pair<int,int> goStright (int direction, int a, int b) /* 현재 지점에서 앞으로 갈 때 (변환 정보가 없을 떄) */
{
    if (direction == right)
    {
        b += 1;
    }
    else if (direction == left)
    {
        b -= 1;
    }
    else if (direction == up)
    {
        a -= 1;
    }
    else if (direction == down)
    {
        a += 1;
    }

    return make_pair(a,b);
}

pair<int,int> goLeft (int direction, int a, int b) /* 현재 지점에서 왼쪽으로 가야할 때 (변환 정보가 있을 때 'L') */
{
    if (direction == right)
    {
        a -= 1;
    }
    else if (direction == left)
    {
        a += 1;
    }
    else if (direction == up)
    {
        b -= 1;
    }
    else if (direction == down)
    {
        b += 1;
    }

    return make_pair(a,b);
}

pair<int,int> goRight (int direction, int a, int b) /* 현재 지점에서 오른쪽으로 가야할 때 (변환 정보가 있을 때 'D') */
{
    if (direction == right)
    {
        a += 1;
    }
    else if (direction == left)
    {
        a -= 1;
    }
    else if (direction == up)
    {
        b += 1;
    }
    else if (direction == down)
    {
        b -= 1;
    }

    return make_pair(a,b);
}

int changeDirection (int currentDirection, char inf) /* 변환 정보가 나왔을 때, direction을 바꾸기 위한 함수 */
{
    int AfterDirection = currentDirection;
    if (inf == 'D')
    {
        switch (currentDirection)
        {
        case right: AfterDirection = down;
            break;
        case left : AfterDirection = up;
            break;
        case up :   AfterDirection = right;
            break;
        case down : AfterDirection = left;
            break;
        }
    }
    else
    {
        switch (currentDirection)
        {
        case right : AfterDirection = up;
            break;
        case left : AfterDirection = down;
            break;
        case up :   AfterDirection = left;
            break;
        case down : AfterDirection = right;
            break;
        }
    }

    return AfterDirection;
}

int solution (int count, int A, int B, int infcount) /* count -> 우리가 구하고자 하는 값, A,B는 머리의 위치, infcount는 information 배열의 idx 위치 */
{
    dq.push_front(make_pair(A,B));

    if (A < 1 || B < 1 || A > N || B > N) /* 벽에 부딪혔을 때, 종료 */
    {
        cout << count;
        exit(0);
    }
    
    for (int i = 1; i < dq.size(); ++i) /* 머리가 몸통에 부딪혔을 때, 종료 */
    {
        if (A == dq[i].first && B == dq[i].second)
        {
            cout << count;
            exit(0);
        }
    }

    if (board[A][B] != apple) /* 사과를 만난게 아니라면 꼬리 제거 */
    {
        dq.pop_back();
    }
    else /* 사과를 먹었다면 사과 제거 */
    {
        board[A][B] = 0;
    }

    pair<int,int> temp; /* 머리가 움직인 곳을 가리키는 temp */

    if (information[infcount].first == count) /* 변환 정보가 있다면, */
    {
        if (information[infcount].second == 'D')
        {
            temp = goRight(dir, A, B);
            A = temp.first;
            B = temp.second;
            dir = changeDirection(dir, 'D');
            solution(count+1, A, B, infcount+1);
        }
        else /* 'L' */
        {
            temp = goLeft(dir, A, B);
            A = temp.first;
            B = temp.second;
            dir = changeDirection(dir, 'L');
            solution(count+1, A, B, infcount+1);
        }
    }
    else
    {
        temp = goStright(dir, A, B);
        A = temp.first;
        B = temp.second;
        solution(count+1, A, B, infcount);
    }

}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();

    solution(1,1,2,0); /* count = 1, 처음 시작은 오른쪽으로 간다했으니 한 칸 이동하고 시작 */

    return 0;
}