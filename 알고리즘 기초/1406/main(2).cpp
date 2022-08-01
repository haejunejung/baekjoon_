/* 
    2회 시도 라이브러리를 쓰지 않고 stack을 구현한 후, 제출하였지만 시간 초과가 떠서 라이브러리로 풀었다 
    라이브러리를 쓰는 것도 실력이라고 봐야하는 것일까 
    정답은 나왔으나, 라이브러리를 쓰지 않고 구현해서 맞춰보고 싶다.     
*/
#include <iostream>
#include <cstring>
#include <stack>

/* stack 구현 */
template <typename T>
class Node
{
public:
    T value;
    Node<T>* next = nullptr;
    Node() {};
    ~Node() {};
};

template <typename T>
class Stack
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Stack() : head(nullptr), tail(nullptr) {}
    ~Stack() {}
    void Push(T value);
    void Pop();
    bool isEmpty();
    T Top();
};

template <typename T>
bool Stack<T>::isEmpty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
T Stack<T>::Top()
{
    return tail->value;
}

template <typename T>
void Stack<T>::Push(T _value)
{
    Node<T>* node = new Node<T>;
    node->value = _value;

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else 
    {
        tail->next = node;
        tail = tail->next;
    }
}

template <typename T>
void Stack<T>::Pop()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node<T>* ptr = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            delete(head);
        }
        else
        {
            while (ptr != nullptr)
            {
                if (ptr->next == tail) 
                {
                    ptr->next = nullptr;
                    delete(tail);
                    tail = ptr;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
}


int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <char> frontSt; /* 커서 앞 쪽의 stack */
    stack <char> backSt; /* 커서 뒤 쪽의 stack */

    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); ++i) {
        frontSt.push(s[i]);
    }

    size_t T, testcase; /* */
    cin >> T;

    for (testcase=1; testcase<=T; testcase++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!frontSt.empty()) {
                backSt.push(frontSt.top());
                frontSt.pop();
            }
        } else if (cmd == 'D') {
            if (!backSt.empty()) {
                frontSt.push(backSt.top());
                backSt.pop();
            }
        } else if (cmd == 'B') {
            if (!frontSt.empty()) {
                frontSt.pop();
            }
        } else {
            char newCharacter;
            cin >> newCharacter;

            frontSt.push(newCharacter);
        }
    }

    while (!frontSt.empty()) {
        backSt.push(frontSt.top());
        frontSt.pop();
    }

    while (!backSt.empty()) {
        cout << backSt.top();
        backSt.pop();
    }

    return 0;
}