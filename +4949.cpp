#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    char data;
    Node* link;
} Node;

Node* Push (Node* stack, char c) {
    Node* newnode = new Node;
    newnode->data = c;
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

char Top (Node* stack) {
    return stack->data;
}

bool IsEmpty (Node* stack) {
    if (stack == nullptr) return true;
    else return false;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin,str,'\n')) {
        if (str == ".") break;
        bool Istrue = true;

        Node* stack = new Node;
        stack = nullptr;

        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (c == '(' || c == '[') {
                stack = Push (stack, c);
            } else if (c == ')') {
                if (IsEmpty(stack) == false && Top(stack) == '(') {
                    stack = Pop(stack);
                } else {
                    Istrue = false;
                    break;
                }
            } else if (c == ']') {
                if (IsEmpty(stack) == false && Top(stack) == '[') {
                    stack = Pop(stack);
                } else {
                    Istrue = false;
                    break;
                }
            } else {
                // character // 
            }
        }

        if (IsEmpty(stack) == true && Istrue == true) cout << "yes\n";
        else cout << "no\n";

    }
    return 0;
}