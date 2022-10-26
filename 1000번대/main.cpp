#include <iostream>
#include <cstring>

using namespace std;

class myPrinter {
private:
    string name;
    int paper;
    int toner;
    void show() { cout << name << " 프린터 종이 수 : " << paper << " 토너 수 : " << toner << endl; }
public:
    myPrinter() {}
    ~myPrinter() { cout << this->name << " 소멸자 실행중... " << endl; }

    void setPrinter (string name, int paper, int toner) { this->name = name; this->paper = paper; this->toner = toner; show(); }
    void usePrinter (int num) { this->paper = this->paper - num; this->toner = this->toner - (num/10); show(); }
    string getName() { return this->name; }
};

void initMyPrinter (myPrinter *variable) {
    variable[0].setPrinter("잉크젯", 200, 100);
    variable[1].setPrinter("레이저젯", 500, 200);
    return;
}

void runMyPrinter (myPrinter *variable, string printerName, int paperNum) {
    for (int i = 0; i < 2; ++i) {
        if (printerName == variable[i].getName()) {
            cout << variable[i].getName() << " 프린터 " << paperNum << " 장 인쇄중... " << endl;
            variable[i].usePrinter(paperNum);
        }
    }
    return;
}

int main () {
    myPrinter *arr = new myPrinter[2];
    initMyPrinter(arr);
    runMyPrinter(arr, "잉크젯", 50);
    runMyPrinter(arr, "레이저젯", 100);
    arr[0].~myPrinter();
    arr[1].~myPrinter();
    return 0;
}