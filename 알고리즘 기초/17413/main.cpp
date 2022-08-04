#include <iostream>
#include <cstring>

template <typename T>
class Node
{
public:
    T vals;
    Node<T>* next;
    Node() {};
    ~Node() {};
};

template <typename T>
class stack
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    stack() : head(nullptr), tail(nullptr) {}
    ~stack() {}
    void push(T value);
    void pop();
    bool empty();
    T top();
};

template <typename T>
void stack<T>::push(T value)
{
    Node<T>* node = new Node<T>;
    node->vals = value;

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = tail;
        tail = node;
    }
}

template <typename T>
void stack<T>::pop()
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete (head);
    }
    else
    {
        Node<T>* ptr = tail->next;
        delete (tail);
        tail = ptr;
    }
}

template <typename T>
bool stack<T>::empty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
T stack<T>::top()
{
    return tail->vals;
}

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S; /* 문장을 받기 위한 문자열 */
    getline(cin, S, '\n');

    stack<char> s; /* 단어를 뒤집어서 출력할 수 있도록 FILO 구조의 stack */
    size_t idx = 0;
    while (idx != S.size()) /* 문장 끝까지 하나씩 보기 위함 */
    {
        if (S[idx] == '<') /* '<' 문자 이후에는 반드시 '>'가 나오므로 '>'까지 그대로 출력 */
        {
            while (!s.empty()) /* '<' 문자 전에 stack에 단어가 쌓여 있었다면, 모두 출력 (거꾸로 출력됨) */
            {
                cout << s.top();
                s.pop();
            }

            cout << S[idx]; 
            while (S[idx] != '>')
            {
                cout << S[++idx];
            }
        }
        else if (S[idx] == ' ') /* 스페이스바가 나오면, 앞에 나온 단어를 잘라냄 */
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << S[idx];
        }
        else /* 위의 조건에 부합하지 않는 경우는, 문자일 때 이므로 push */
        {
            s.push(S[idx]);
        }
        idx++;
    }
    while (!s.empty()) /* 마지막에 남은 단어가 있는지 확인 */
    {
        cout << s.top();
        s.pop();
    }

    return 0; /* 올바르게 종료 */
}