// Traveling Salesman problem (TSP) //
// 1 ~ N 번호 매겨진 도시들과 길이 있다 (길은 없을 수도 있다)
// 한 도시에서 출발해 N 개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로
// 단, 한 번 갔던 도시로는 다시 갈 수 없다 (맨 마지막에 여행을 출발했던 도시로 돌아오는 것 제외)
// W[i][j] 형태로 비용 제시
// W[i][i] 는 항상 0, W[i][j] = 0 인 경우는 갈 수 없는 경우로 판단
// 가장 적은 비용으로 순회 여행 경로 파악

#include <iostream>
#include <algorithm>

#define Max 11
#define maximum 1000000 * 9 + 1

using namespace std;

int N, W[Max][Max], ans = maximum;
bool visited[Max];

void Initialize () {
    
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> W[i][j];
        }
    }
}

void Solution (int cnt, int sum, int start, int start_point) {
    if (cnt == N) {
        if (W[start][start_point] == 0) return;
        ans = min (ans , sum + W[start][start_point]);
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i] == false && W[start][i] != 0) {
            visited[i] = true;
            Solution (cnt+1, sum + W[start][i], i, start_point);
            visited[i] = false;
        }
    }    
}



int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Initialize ();   
    for (int i = 1; i <= N; ++i) {
        visited[i] = true;
        Solution (1,0,i,i); // 갯수 count, 가격 합, 시작 점 //
        visited[i] = false;
    }

    cout << ans;
    return 0;
}