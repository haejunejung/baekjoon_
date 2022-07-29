#include <iostream>
#include <cstring>

#define integer int
#define PU "push"
#define PP "pop"
#define T "top"
#define S "size"
#define E "empty"


struct Node
{
    integer val;
    Node* link;
};

Node* push (integer X, Node* node) {
    Node* temp = new Node; /* 새로운 노드 생성 */ 
    temp->val = X; /* 새로운 노드의 value */
    temp->link = node; /* 새로운 노드의 링크를 기존 노드를 가리키게 한 후 기존 노드를 새 노드로 변경 */
    node = temp;
    return node;
}

integer size (Node* node) {
    integer count = 0;
    while (!(node->link == nullptr)) {
        node = node->link;
        count++;
    }

    return count;
}

bool empty (Node* node) {
    if (size(node) == 0) {
        return true;
    } else {
        return false;
    }
}

integer top (Node* node) {
    if (!empty(node)) {
        return node->val;
    } else {
        return -1;
    }
}

Node* pop (Node* node) {
    if (empty(node)) {
        std::cout << -1 << '\n';
        return node;
    } else {
        std::cout << node->val << '\n';
        Node* temp = new Node;
        temp = node->link;
        delete (node);
        return temp;
    }
}


int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *node = new Node;
    node->link = nullptr;

    int N, testcase;
    cin >> N;

    for (testcase=1; testcase<=N; ++testcase) {
        string str;
        cin >> str;

        if (str == PU) {
            integer X; 
            cin >> X;

            node = push(X, node);    
        } else if (str == PP) {
            node = pop(node);
        } else if (str == T) {
            cout << top(node) << '\n';
        } else if (str == S) {
            cout << size(node) << '\n';
        } else {
            cout << empty(node) << '\n';
        }
    }

    delete node;
    return 0;
}