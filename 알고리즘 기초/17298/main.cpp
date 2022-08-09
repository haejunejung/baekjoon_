#include <iostream>

template <typename T>
class Node
{
public:
    T val;
    Node<T>* next;
    Node() {}
    ~Node() {}
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
    node->val = value;

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
        delete head;
    }
    else
    {
        Node<T>* ptr = tail->next;
        delete tail;
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
    return tail->val;
}

int main (void) {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *sequence = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> sequence[i];
    }

    stack <int> s;
    stack <int> ans;

    for (int i = N-1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= sequence[i])
        {
            s.pop();
        }

        if (s.empty()) ans.push(-1);
        else ans.push(s.top());

        s.push(sequence[i]);
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}