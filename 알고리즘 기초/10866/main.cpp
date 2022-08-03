#include <iostream>
#include <cstring>

template <typename T>
class Node
{
public:
    T val;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node() {};
    ~Node() {};
};

template <typename T>
class Deque
{
private :
    Node<T>* head;
    Node<T>* tail;
    size_t length;
public :
    Deque() : head (nullptr), tail (nullptr), length(0) {}
    ~Deque() {}
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    size_t size();
    bool empty();
    T front();
    T back();
};

template <typename T>
void Deque<T>::push_front(T value)
{
    Node<T>* node = new Node<T>;
    node->val = value;

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->right = head;
        head->left = node;
        head = node;
    }

    length++;
}

template <typename T>
void Deque<T>::push_back(T value)
{
    Node<T>* node = new Node<T>;
    node->val = value;

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->left = tail;
        tail->right = node;
        tail = node;
    }

    length++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete (head);
    }
    else
    {
        Node<T>* ptr = head->right;
        head = nullptr;
        delete (head);
        head = ptr;
    }

    length--;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete (head);
    }
    else
    {
        Node<T>* ptr = tail->left;
        tail = nullptr;
        delete (tail);
        tail = ptr;
    }

    length--;
}

template <typename T>
size_t Deque<T>::size()
{
    return length;
}

template <typename T>
bool Deque<T>::empty()
{
    return tail == nullptr ? true : false;
}

template <typename T>
T Deque<T>::front()
{
    return head->val;
}

template <typename T>
T Deque<T>::back()
{
    return tail->val;
}

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    size_t N;
    cin >> N;

    Deque <int> dq;
    for (size_t i = 1; i <= N; ++i)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back")
        {
            int X;
            cin >> X;

            dq.push_back(X);
        }
        else if (cmd == "push_front")
        {
            int X;
            cin >> X;
            
            dq.push_front(X);
        }
        else if (cmd == "pop_back")
        {
            if (!dq.empty()) 
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if (cmd == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            } 
            else cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (!dq.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (cmd == "front")
        {
            if (!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "back")
        {
            if (!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}