
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(struct TreeNode* node) {
    
    if(node == NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if(lheight > rheight)
            return (lheight+1);
        else return (rheight+1);
    }
}

void printGivenLevel(struct TreeNode* root, int level) {

    if(root == NULL) return;

    if(level == 1){
        cout << root->val;
    } else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct TreeNode* root) {

    int h = height(root);
    cout << "Level with a given root: " << h << endl;
    for(int i=1; i<=h; i++){
        printGivenLevel(root, i);
        cout << endl;
    }
    cout << endl;
}

void printReverseLevelOrder(struct TreeNode* root) {

    int h = height(root);
    for(int i=h; i>=1; i--)
        printGivenLevel(root, i);
    cout << endl;
}

int main() {
    
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Level order traversal of binary tree is "<< endl;
    printLevelOrder(root);
    
    return 0;
}
