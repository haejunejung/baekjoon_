#include <iostream>
#include <cstring>
#include <algorithm>

typedef struct {
    std::string name;
    int korean;
    int english;
    int math;
} STUDENT;

bool Compare(const STUDENT& p1, const STUDENT& p2) {
    if (p1.korean == p2.korean) {
        if (p1.english == p2.english) {
            if (p1.math == p2.math) {
                if (p1.name.compare(p2.name) > 0) return false;
                else return true;
            } else return p1.math > p2.math;
        } else return p1.english < p2.english;
    } else return p1.korean > p2.korean;
}

void Interchange (STUDENT *a, STUDENT *b) {
    STUDENT temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main () {
    using namespace std;

    int N;
    cin >> N;

    STUDENT *student = new STUDENT[N];
    for (int i = 0; i < N; ++i) {
        string str;
        int a,b,c;
        cin >> str >> a >> b >> c;
        student[i].name = str;
        student[i].korean = a;
        student[i].english = b;
        student[i].math = c;
    }

    sort(student, student+N, Compare);

    // for (int i = 0; i < N; ++i) {
    //     cout << student[i].name << " " << student[i].korean << " "
    //         << student[i].english << " " << student[i].math << "\n";
    // }

    // for (int i = 0; i < N; ++i) {
    //     for (int j = i + 1; j < N; ++j) {
    //         if (student[i].korean < student[j].korean) {
    //             Interchange(&student[i], &student[j]);
    //         } else if (student[i].korean == student[j].korean) {
    //             if (student[i].english > student[j].english) {
    //                 Interchange(&student[i], &student[j]);
    //             } else if (student[i].english == student[j].english) {
    //                 if (student[i].math < student[j].math) {
    //                     Interchange(&student[i], &student[j]);
    //                 } else if (student[i].math == student[j].math) {
    //                     if (student[i].name.compare(student[j].name) > 0) {
    //                         Interchange(&student[i], &student[j]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    for (int i = 0; i < N; ++i) {
        cout << student[i].name << "\n";
    }

    return 0;
}