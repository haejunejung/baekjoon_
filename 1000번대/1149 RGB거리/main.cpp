#include <iostream>

#define max 1000

int main () {
    using namespace std;

    int N;
    cin >> N;

    int rgb[max][3];
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> rgb[i][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        rgb[i][0] = min(rgb[i-1][1] , rgb[i-1][2]) + rgb[i][0];
        rgb[i][1] = min(rgb[i-1][0] , rgb[i-1][2]) + rgb[i][1];
        rgb[i][2] = min(rgb[i-1][0] , rgb[i-1][1]) + rgb[i][2];
    }

    int ans = min (rgb[N-1][0] , min (rgb[N-1][1] , rgb[N-1][2]));
    std::cout << ans << std::endl;

    return 0;
}