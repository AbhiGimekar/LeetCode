/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;

    if (!root)
        return root;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node *last = nullptr;
        for (int i = 0; i < size; i++) {
            auto n = q.front();                
            q.pop();
            if (last)
                n->next = last;
            last = n;
            if (n->right)
                q.push(n->right);
            if (n->left)
                q.push(n->left);
        }
    }
    return root;
    }
};