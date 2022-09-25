/* 
    1. 지역구를 2개로 나눌 때, dfs를 이용한다
    2. 이 때, check -> true A선거구 , check -> false B선거구로 선정하였다
    3. 지역구를 나눌 때 구역을 한 선거구가 N/2만큼의 구역을 차지할 때까지 하였다. 왜냐하면 (1,5)와 (5,1)의 값은 똑같기 때문이다
    4. 이후 모두 연결되어 있는 함수를 만든다
    5. 여기서 조심해야 할 점은 2개의 선거구라는 점이다. 
    6. 모두 연결되어있는지만 판단하게 되면 3개 이상의 선거구여도 통과해버리기 때문에, queue를 사용하였다 (1차 시도에서 틀린 이유)
    7. 모두 연결되어 있다면, 인구 차이의 최솟값을 구한다

    3개의 선거구도 나올 수 있다는 사실을 몰라서 고생했던 문제였다.
    union-find로도 구할 수 있다고 들었는데 나중에 기회가 되면 union-find로 구해봐야겠다
    조금 더 신경써서 문제 풀어야겠다 ...
*/

#include <iostream>
#include <queue>

using namespace std;

#define MAX 987654321

int N; /* 구역의 수 */
int res; /* 결과값 */
int person[11]; /* 인구수 */
bool check[11]; /* 두 선거구의 구역을 나누기 위한 배열 */
bool connection[11][11]; /* 연결되어 있는지 확인하는 배열 */

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> person[i];
    }

    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int part;
            cin >> part;

            connection[i][part] = true;
        }
    }

    res = MAX; /* 시작값을 최댓값으로 설정하여 min함수를 사용할 수 있도록 하였다 */
}

void ComparePopulation () { /* 인구 차이를 비교하는 함수 */
    int sum_A = 0, sum_B = 0;
    for (int i = 1; i <= N; ++i) {
        if (check[i]) sum_A += person[i];
        else sum_B += person[i];
    }

    res = min (res, abs(sum_A - sum_B));
}

bool IsAllConnect () { /* 모두 연결 되어 있는지 확인하는 함수 */
    queue <int> q;
    bool *IsconnectEachParty = new bool[N+1];

    /* 선거구 A */
    for (int i = 1; i <= N; ++i) {
        if (check[i]) {
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int nod = q.front();
        IsconnectEachParty[nod] = true;
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (check[i] && connection[nod][i] && !IsconnectEachParty[i]) {
                q.push(i);
            }
        }
    }

    /* 선거구 B */
    for (int i = 1; i <= N; ++i) {
        if (!check[i]) {
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int nod = q.front();
        IsconnectEachParty[nod] = true;
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (!check[i] && connection[nod][i] && !IsconnectEachParty[i]) {
                q.push(i);
            }
        }
    }

    /* 모두 연결되어 있는지 마지막으로 확인 */
    for (int i = 1; i <= N; ++i) {
        if (!IsconnectEachParty[i]) return false;
    }
    
    return true;
}

void dfs (int count, int purposeCount) { /* 각각의 구역을 나누는 dfs */
    if (count == purposeCount) {
        if (IsAllConnect ()) {
            ComparePopulation ();
        }
        return;
    }

    for (int i = count+1; i <= N; ++i) {
        if (!check[i]) {
            check[i] = true;
            dfs (count +1, purposeCount);
            check[i] = false;
        }
    }
}

void solution () {
    for (int i = 1; i <= N/2; ++i) { /* 절반까지만 확인하여 시간 줄이기 */
        for (int j = 1; j <= N; ++j) check[j] = false;
        dfs (0, i);
    }

    if (res == MAX) cout << -1; /* 선거구가 두 개로 안나뉘어질 때 -1로 출력 */
    else cout << res; /* 두 개로 나눠지는 경우가 있을 때, 결과값 출력 */
}

int main (void) {
    input ();
    solution ();
    return 0; /* 정상적으로 돌아갔을 경우 return 0 종료 */
}