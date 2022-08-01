#include <iostream>
#include <cstring>

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
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t countSize;
public:
    Queue() : head(nullptr), tail(nullptr), countSize(0) {}
    ~Queue() {}
    void push(T value);
    void Pop();
    size_t size();
    bool empty();
    T front();
    T back();
};

template <typename T>
bool Queue<T>::empty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
size_t Queue<T>::size()
{
    return countSize;
}

template <typename T>
void Queue<T>::push(T _value)
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

    countSize++;
}

template <typename T>
void Queue<T>::Pop()
{
    if (empty()) return;
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
            ptr = head->next;
            delete(head);
            head = ptr;
        }
    }

    countSize--;
}

template <typename T>
T Queue<T>::front()
{
    return head->value;
}

template <typename T>
T Queue<T>::back()
{
    return tail->value;
}

int main (void) {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t T, testcase;
    cin >> T;

    Queue <int> q;

    for (testcase=1; testcase<=T; ++testcase)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int n;
            cin >> n;

            q.push(n);
        }
        else if (cmd == "pop") 
        {
            if (q.empty()) 
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.Pop();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (cmd == "back")
        {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;

}