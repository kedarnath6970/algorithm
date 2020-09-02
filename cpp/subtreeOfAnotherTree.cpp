
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* node) {
    
    if (node == NULL) return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight)
        return lheight + 1;
    else return rheight + 1;
}

TreeNode* findRoot(TreeNode* s, int val) {
    TreeNode* left, *right;

    if (s == NULL) return NULL;

    if (s->val == val) return s;
    else {
        left = findRoot(s->left, val);
        right = findRoot(s->right, val);
    }

    if (left != NULL) return left;
    if (right != NULL) return right;

    return NULL;
}

bool hasSubtree(TreeNode* s, TreeNode* t) {
    
    if (s == NULL && t == NULL) return true;
    else if (s != NULL && t == NULL) return false;
    else if (s == NULL && t != NULL) return false;

    return hasSubtree(s->left, t->left) &&
        hasSubtree(s->right, t->right); 
}

bool subtreeOfAnotherTree(TreeNode* s, TreeNode* t) {

    int sheight = height(s);
    int theight = height(t);
 
    if (theight > sheight) return false;

    TreeNode* root = findRoot(s, t->val);

    if (hasSubtree(root, t)) return true;
    else return false;
}


int main() {

    struct TreeNode* s = new struct TreeNode(3);
    s->left = new struct TreeNode(4);
    s->right = new struct TreeNode(5);
    s->left->left = new struct TreeNode(1);
    s->left->right = new struct TreeNode(2);
    s->left->right->left = new struct TreeNode(0);

    struct TreeNode* t = new struct TreeNode(4);
    t->left = new struct TreeNode(1);
    t->right = new struct TreeNode(2);

    if (subtreeOfAnotherTree(s, t)) {
        cout << "t is a subtree of s" << endl;   
    } else {
        cout << "t is not a subtree of s" << endl;
    }
    
    return 0;
}
