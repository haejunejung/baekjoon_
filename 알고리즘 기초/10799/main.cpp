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
    size_t length;
public:
    stack() : head(nullptr), tail(nullptr), length(0) {}
    ~stack() {}
    void push(T value);
    void pop();
    T top();
    bool empty();
    size_t size();
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

    length++;
}

template <typename T>
void stack<T>::pop()
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete head;
    }
    else
    {
        Node<T>* ptr = tail->next;
        delete tail;
        tail = ptr;
    }

    length--;
}

template <typename T>
T stack<T>::top()
{
    return tail->vals;
}

template <typename T>
bool stack<T>::empty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
size_t stack<T>::size()
{
    return length;
}

int main () 
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    size_t idx = 0, count = 0; /* count -> 답 */
    stack <char> s; /* 막대기를 담기 위한 stack */
    while (!(idx == input.size()))
    {
        if (input[idx] == '(') /* '('이 나왔을 때는 stack에 push */
        {
            s.push(input[idx]);
        }
        else if (input[idx] == ')') /* ')'이 나오는 경우는, 막대기를 표현할 때와 레이저를 표현할 때 2가지로 나눈다 */
        {
            if (input[idx-1] == '(') /* 레이저일 경우, 이전까지 stack에 남아있는 막대기 수를 count에 더해준다 */
            {
                s.pop();
                count += s.size();
            }
            else /* 막대기의 마지막인 경우는, 이제 앞으로 그 막대기는 사용하지 않으므로 마지막 조각 1개를 더해준다 */
            {
                s.pop();
                count += 1;
            }
        }

        idx++;
    }

    while (!s.empty())
    {
        s.pop();
    }

    cout << count; 
    return 0; /* 완료되면 종료 */
}