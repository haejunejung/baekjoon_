#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int N, MAX, OperatorNum; /* N -> input길이, max -> 답, Count each */
string str; /* input으로 받을 string 생성 */
char Operator[9]; /* 연산자들 */
int Operand[10]; /* 피연산자들 */

void input ()
{
    cin >> N >> str;
    int CountOperator=0; /* Operator의 갯수 (배열에 넣기 위함) */
    int CountOperand=0; /* Operand의 갯수 (배열에 넣기 위함) */
    MAX = INT_MIN; /* -2^31가 나올 수 있으므로, 시작점을 최소가 될 수 있는 INT_MIN으로 지정 */

    for (size_t i=0; i<str.length(); ++i)
    {
        if (i%2 == 0)   Operand[CountOperand++] = str[i] - '0'; 
        else            Operator[CountOperator++] = str[i];
    }

    OperatorNum = N / 2;
}

int calculator (int x, int y, char oper)
{
    switch (oper)
    {
    case '+' : return x+y;
    case '-' : return x-y;
    case '*' : return x*y;
    
    default:
        return 0;
    }
}

void DFS (int Idx, int res) /* Idx : operator의 위치, res : 현재까지 계산된 값 */
{
    if (Idx >= OperatorNum)
    {
        MAX = std::max(MAX, res);
        return;
    }

    int straightResult = calculator (res, Operand[Idx+1], Operator[Idx]); /* 현재까지 계산된 값에 순차적으로 계산 */
    DFS (Idx+1, straightResult); /* 순차적으로 계산 (왼쪽부터), 재귀 */

    if (Idx + 1 < OperatorNum) /* Idx+1 == OperatorNum 일 경우, 뒤에 괄호를 칠 수 없으므로 조건문 */
    {
        int bracketResult = calculator (Operand[Idx+1], Operand[Idx+2], Operator[Idx+1]); /* 괄호 쳐서 계산 */
        DFS (Idx+2, calculator(res, bracketResult, Operator[Idx])); /* 다음 괄호를 만들기 위해 재귀 */
    }
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    DFS (0, Operand[0]); /* 0은 Operator배열이 시작하는 지점, Operand[0]로 놓은 이유는 N이 1인 경우도 포함하기 위함 */

    cout << MAX;

    return 0;


}