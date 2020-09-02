
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


TreeNode* trimBST(TreeNode* node, int lower, int upper) {
    if (node == NULL) return NULL;

    cout << "Node value: " << node->val << endl;
    if (node->val < lower) {
        if (node->right != NULL) {
            node = node->right;
        } else {
            return NULL;
        }
    }

    if (node->val > upper) {
        if (node->left != NULL) {
            node = node->left;
        } else {
            return NULL;
        }
    }

    node->left = trimBST(node->left, lower, upper);
    node->right = trimBST(node->right, lower, upper);
    return node;
}

void printPostOrderTraversal(TreeNode* node) {
    
    if (node == NULL)
        return ;

    printPostOrderTraversal(node->left);
    printPostOrderTraversal(node->right);
    cout << node->val << endl;
}

int main() {

    TreeNode* root = new struct TreeNode(3);
    root->left = new struct TreeNode(0);
    root->right = new struct TreeNode(4);
    root->left->right = new struct TreeNode(2);
    root->left->right->left = new struct TreeNode(1);

    TreeNode* new_root = trimBST(root, 1, 3);
    printPostOrderTraversal(new_root);
}
