
#include <iostream>
#include <queue>
#include <stack>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void reverseOrderTraversal(TreeNode* root) {

    stack<TreeNode*> node_stack;
    queue<TreeNode*> node_queue;
    node_queue.push(root);

    while(node_queue.empty() == false) {
        root = node_queue.front();
        node_queue.pop();
        node_stack.push(root);

        if(root->right)
            node_queue.push(root->right);

        if(root->left)
            node_queue.push(root->left);
    }

    while(node_stack.empty() == false) {
        cout << node_stack.top()->val;
        node_stack.pop();
    }
    cout << endl;
}

int main() {

    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Reverse level order traversal is ";
    reverseOrderTraversal(root);

    return 0;
}
