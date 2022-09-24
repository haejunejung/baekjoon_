#include <iostream>
#include <utility>

int C,P;
int map[100];

int count_one () {
    int count = C;
    for (int i = 0; i < C-3; ++i) {
        int flag = map[i];
        for (int j = i; j < i+4; ++j) {
            if (flag != map[j]) flag = -1;
        }

        if (flag != -1) count++;
    }
    return count;
}

int count_two () {
    int count = 0;
    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]) count++;
    }
    return count;
}

int count_three () {
    int count = 0;
    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i] && map[i] == map[i+1]-1) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]+1) count++;
    }
    return count;
}

int count_four () {
    int count = 0;
    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i]+1 && map[i] == map[i+1]) count++;
    }
    
    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]-1) count++;
    }
    return count;
}

int count_five () {
    int count = 0;
    for (int i = 0; i < C-2; ++i) {
        if (map[i] == map[i+1] && map[i+1] == map[i+2]) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]+1) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]-1) count++;
    }

    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i]+1 && map[i]+1 == map[i+1]) count++;
    }
    return count;
}

int count_six () {
    int count =0;
    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i] && map[i] == map[i+1]) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]) count++;
    }

    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i]-1 && map[i] == map[i+1]) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]+2) count++;
    }

    return count;
}

int count_seven () {
    int count = 0;
    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i] && map[i] == map[i+1]) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]) count++;
    }

    for (int i = 1; i < C-1; ++i) {
        if (map[i-1] == map[i] && map[i] == map[i+1]+1) count++;
    }

    for (int i = 0; i < C-1; ++i) {
        if (map[i] == map[i+1]-2) count++;
    }

    return count;
}

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> C >> P;

    for (int i = 0; i < C; ++i) {
        cin >> map[i];
    }

    unsigned count = 0;
    switch (P)
    {
    case 1: count = count_one();
        break;

    case 2: count = count_two();
        break;
    
    case 3: count = count_three();
        break;

    case 4: count = count_four();
        break;

    case 5: count = count_five();
        break;

    case 6: count = count_six();
        break;

    case 7: count = count_seven();
        break;
    default:
        break;
    }

    cout << count;
    return 0;
}