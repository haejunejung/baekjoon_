#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int board[16][16];
int map[16][16];
int archer[16];
int N, M, D, NumEnemy, res;
vector <pair<int,int>> v;

void input (void)
{
    cin >> N >> M >> D;
    res = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j]) NumEnemy++;
        }
    }
}

void moveMap ()
{
    for (int i = N; i >= 2; --i)
    {
        for (int j = 1; j <= M; ++j)
        {
            map[i][j] = map[i-1][j];
        }
    }
}

bool FindKillPos (int archerPosX, int archerPosY, int x, int y, int dis)
{
    if (x < 1 || y < 1 || x > N || y > N) return false;
    if (abs(archerPosX - x) + abs(archerPosY - y) > D || abs(archerPosX - x) + abs(archerPosY - y) != dis) return false;
    if (map[y][x] == 1)
    {
        bool flag = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].first == x && v[i].second == y)
            {
                flag = true;
            }
        }
        if (!flag) v.push_back(make_pair(x,y));
        return true;
    }

    while (dis <= D)
    {
        dis++;

        if(FindKillPos (archerPosX, archerPosY, x-1, y, dis)) break;
        if(FindKillPos (archerPosX, archerPosY, x, y-1, dis)) break;
        if(FindKillPos (archerPosX, archerPosY, x+1, y, dis)) break;
    }

    return false;
}

void Kill ()
{
    for (int i = 1; i <= M; ++i)
    {
        if (archer[i])
        {
            FindKillPos (i, N+1, i, N, 1);
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        int dx = v[i].first;
        int dy = v[i].second;

        // cout << "y : " << dy << " x : " << dx << "\n";
        map[dy][dx] = 0;
    }
    // cout << "\n";
}

void solution ()
{

    
    int NumKill = 0;
    for (int i = 1; i <= N; ++i)
    {

        if (i != 1)
        {
            moveMap ();
        }
        

        Kill ();
        NumKill += v.size();
        v.clear();

        if (NumKill >= NumEnemy) 
        {
            cout << NumEnemy << "\n";
            exit(0);
        }
    }

    res = max(res, NumKill);
}

void dfs (int CntArcher, int pos)
{
    if (CntArcher == 3)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                map[i][j] = board[i][j];
            }
        }

        solution ();
    }

    for (int i = pos+1; i <= M; ++i)
    {
        if (!archer[i])
        {
            archer[i] = 1;
            dfs (CntArcher+1, i);
            archer[i] = 0;
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input ();
    dfs (0, 1);

    cout << res;
    return 0;
}

