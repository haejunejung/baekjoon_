#include <iostream>

template <typename T>
class Node
{
public:
    T vals;
    Node<T>* link = nullptr;
    Node() {};
    ~Node() {};
};

template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue() {};
    void Push(T value);
    void Pop();
    bool IsEmpty();
    T Front();
};

template <typename T>
void Queue<T>::Push(T value)
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
        tail->link = node;
        tail = tail->link;
    }
}

template <typename T>
void Queue<T>::Pop()
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete(head);
    }
    else
    {
        Node<T>* ptr = head->link;
        delete(head);
        head = ptr;
    }
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
T Queue<T>::Front()
{
    return head->vals;
}


int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;

    Queue <int> q;
    for (int i = 1; i <= N; ++i) {
        q.Push(i);
    }

    int cnt = 1;

    cout << '<';
    while (!q.IsEmpty())
    {
        if (cnt == K)
        {
            cout << q.Front();
            q.Pop();
            if (!q.IsEmpty()) cout << ", ";
            cnt = 1;
        }
        else
        {
            q.Push(q.Front());
            q.Pop();
            cnt++;
        }
    }
    cout << '>';

    return 0;
}