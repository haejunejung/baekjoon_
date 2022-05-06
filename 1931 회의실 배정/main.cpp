#include <iostream>
#include <utility>

#define Max 100000

int main (void) {
    using namespace std;

    int N;

    cin >> N;

    std::pair <unsigned int, unsigned int> time[Max];
    for (int i = 0; i < N; ++i) {
        unsigned int x, y;
        cin >> x >> y;
        time[i].first = x;
        time[i].second = y;
    }

    
    
}