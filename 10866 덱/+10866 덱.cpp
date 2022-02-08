#include <iostream>
#include <string>

using namespace std;

// not using STL queue //

typedef struct Node {
    int data;
    Node* prev;
    Node* next;
} Node;

typedef struct Queue {
    int count; // Queue Node count //
    Node* front;
    Node* back;
} Queue;

void InitQueue (Queue* q) {
    q->front = nullptr;
    q->back  = nullptr;
    q->count = 0;
}

Queue* Push_front (Queue* q, int n) {
    if (q->front == nullptr && q->back == nullptr) {
        Node* newnode = new Node;
        newnode->data = n;
        q->front = newnode;
        q->back  = newnode;
        q->count++;
    } else {
        Node* newnode = new Node;
        newnode->data = n;
        q->front->prev = newnode;
        newnode->next = q->front;
        q->front = newnode;
        q->count++;
    }

    return q;
}

Queue* Push_back (Queue* q, int n) {
    if (q->front == nullptr && q->back == nullptr) {
        Node* newnode = new Node;
        newnode->data = n;
        q->front = newnode;
        q->back  = newnode;
        q->count++;
    } else {
        Node* newnode = new Node;
        newnode->data = n;
        q->back->next = newnode;
        newnode->prev = q->back;
        q->back = newnode;
        q->count++;
    }

    return q;
}

int Size (Queue* q) {
    return q->count;
}

bool IsEmpty (Queue* q) {
    if (q->count == 0) return true;
    else return false;
}

Queue* Pop_front (Queue* q) {
    if (q->front == q->back) {
        delete(q->front);
        q->front = q->back = nullptr;
    } else {
        Node* newnode = q->front->next;
        delete(q->front);
        q->front = nullptr;

        q->front = newnode;
    }
    q->count--;

    return q;
}

Queue* Pop_back (Queue* q) {
    if (q->back == q->front) {
        delete(q->back);
        q->back = q->front = nullptr;
    } else {
        Node* newnode = q->back->prev;
        delete(q->back);
        q->back = nullptr;

        q->back = newnode;
    }
    q->count--;

    return q;
}

int Front (Queue* q) {
    return q->front->data;
}

int Back (Queue* q) {
    return q->back->data;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue* q = new Queue;
    InitQueue(q);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        if (str == "push_front") {
            int n;
            cin >> n;
            q = Push_front(q,n);
        } 
        
        else if (str == "push_back") {
            int n;
            cin >> n;
            q = Push_back(q,n);
        }

        else if (str == "pop_front") {
            if (IsEmpty(q) == true) cout << -1 << '\n';
            else {
                cout << Front(q) << '\n';
                q = Pop_front(q);
            }
        }

        else if (str == "pop_back") {
            if (IsEmpty(q) == true) cout << -1 << '\n';
            else {
                cout << Back(q) << '\n';
                q = Pop_back(q);
            }
        }

        else if (str == "size") {
            cout << Size(q) << '\n';
        }

        else if (str == "empty") {
            if (IsEmpty(q) == true) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        else if (str == "front") {
            if (IsEmpty(q) == true) cout << -1 << '\n';
            else cout << Front(q) << '\n';
        }

        else if (str == "back") {
            if (IsEmpty(q) == true) cout << -1 << '\n';
            else cout << Back(q) << '\n';
        }
    }

    return 0;
    
}