
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


int height(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));    
}

void printGivenLevel(TreeNode* node, int h, bool ltr, bool last) {

    if (node == NULL) return;

    if (h == 1){
        if (!last) 
            cout << node->val << ",";
        else
           cout << node->val;
    } 

    if (ltr) {
        printGivenLevel(node->left, h-1, ltr, false);
        printGivenLevel(node->right, h-1, ltr, true);
    } else {
        printGivenLevel(node->right, h-1, ltr, false);
        printGivenLevel(node->left, h-1, ltr, true);
    }
}

void zigzagTraversal(TreeNode* node) {
    
    bool ltr = false, last = false;
    int h = height(node);
    
    cout << "[" << endl;
    for (int i=1; i<=h; i++) { 
        cout << "[";
        if (i==1) last = !last;
        printGivenLevel(node, i, ltr, last);
        ltr = !ltr;
        if (i < h)
            cout << "]," << endl;
        else
            cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {

    TreeNode* root = new struct TreeNode(3);
    root->left = new struct TreeNode(9);
    root->right = new struct TreeNode(20);
    root->right->left = new struct TreeNode(15);
    root->right->right = new struct TreeNode(7);

    zigzagTraversal(root);

    return 0;
}
