#include <iostream>

using namespace std;

typedef struct Node {
    int n;
    Node* link;
} Node;

Node* Push (Node* stack , int num) {
    Node* newnode = new Node;
    newnode->n = num;
    newnode->link = stack;
    stack = newnode;

    return stack;
}

Node* Pop (Node* stack) {
    Node* newnode = new Node;
    newnode = stack->link;
    delete(stack);
    stack = nullptr;
    stack = newnode;

    return stack;
}

int Top (Node* stack) {
    return stack->n;
}

bool Empty (Node* stack) {
    if (stack == nullptr) return true;
    else return false;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    int num;
    Node* stack = new Node;
    stack = nullptr;

    for (int i = 0; i < K; ++i) {
        cin >> num;
        if (num == 0) {
            stack = Pop(stack);
        } else {
            stack = Push(stack,num);
        }
    }

    unsigned long long sum = 0;
    while (Empty(stack) != true)
    {
        sum += Top(stack);
        stack = Pop(stack);
    }

    cout << sum;
    return 0;

}