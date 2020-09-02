
#include <iostream>
#include <deque>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(struct TreeNode* node, deque<int>& nodeVal) {

    if (node == NULL) return;

    inorderTraversal(node->left, nodeVal);
    nodeVal.push_back(node->val);
    inorderTraversal(node->right, nodeVal);
}

bool isSymmetricTree(deque<int> nodeVal) {

    if (nodeVal.size() % 2 == 0) return false;
    
    int front, back;
    while (nodeVal.size() > 1) {
        front = nodeVal.front();
        back = nodeVal.back();

        if (front != back) return false;
        else {
            nodeVal.pop_front();
            nodeVal.pop_back();
        }
    }
    return true;
}

int main() {
    
    struct TreeNode* root = new struct TreeNode(1);
    root->left = new struct TreeNode(2);
    root->right = new struct TreeNode(2);
    root->left->left = new struct TreeNode(3);
    root->left->right = new struct TreeNode(4);
    root->right->left = new struct TreeNode(4);
    root->right->right = new struct TreeNode(3);

    deque<int> nodeVal;
    inorderTraversal(root, nodeVal);
    
    if (isSymmetricTree(nodeVal)) {
        cout << "Tree is symmetric." << endl;
    } else {
        cout << "Tree is not symmetric." << endl;
    }
    return 0;
}
