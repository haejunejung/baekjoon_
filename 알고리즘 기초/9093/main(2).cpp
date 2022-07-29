/* 
    2차 시도 -> stack을 이용하여 시간을 조금 줄일 수 있었지만,
    여전히 느린 것을 확인하였다.. -> 라이브러리를 쓰지 않고 속도를 높일 수 있을 방안에 대해
    생각해보면 좋을 것 같다.

    다음 문제부터는 클린 코드로 작성할 수 있게끔 .. 
*/

#include <iostream>

struct Node
{
    char vals;
    Node* link;
};


Node* Push (char val, Node* node) { /* stack 에서의 Push */
    Node* temp = new Node;
    temp->vals = val;
    temp->link = node;
    node = temp;

    return node;
}

Node* Pop (Node* node) { /* stack 에서의 Pop */
    Node* temp = node->link;
    delete (node);

    return temp;
}

int Size (Node* node) { /* stack 에서의 Size */ 
    int size = 0;
    while (!(node->link == nullptr)) {
        node = node->link;
        size++;
    }
    
    return size;
}

bool Empty (Node* node) { /* stack 에서의 empty 확인 */
    if (Size(node) == 0) return true;
    else return false;
}


int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;
    cin.ignore();

    for (testcase=1; testcase<=T; testcase++) {
        char ch[1001]; /* 문장을 받을 배열 */
        cin.getline(ch, 1000, '\n');

        Node* node = new Node;
        node->link = nullptr;

        unsigned short count = 0; /* 받은 문장의 길이 */
        while (ch[count]) {
            count++;
        }

        ch[count] = ' '; /* 문장 마지막에 스페이스바 추가 -> 스페이스바가 나올 때마다의 조건문 활용 가능 */

        for (int i = 0; i <= count; ++i) {

            if (ch[i] == ' ') {
                while (!Empty(node)) { /* 단어 거꾸로 출력*/
                    cout << node->vals;
                    node = Pop(node);
                }

                cout << " "; /* 단어 출력한 후, 스페이스바 출력 */
            } else {
                node = Push(ch[i], node); /* 단어를 stack에 추가 */
            }
        }

        cout << endl;

        while (!Empty(node)) { /* 메모리 누수 없애기 ? */
            node= Pop(node);
        }

        delete (node);
    }

    return 0;
}