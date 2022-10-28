#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int exam_score;
    cin >> exam_score;

    if (exam_score >= 90 && exam_score <= 100) cout << 'A' << endl;
    else if (exam_score >= 80) cout << 'B' << endl;
    else if (exam_score >= 70) cout << 'C' << endl;
    else if (exam_score >= 60) cout << 'D' << endl;
    else cout << 'F' << endl; 

    return 0;
}