
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

void  maxBinaryTree(TreeNode** root, int elems[], int start, int num_of_elems) {
    
    if (num_of_elems == 0) return;

    struct TreeNode* node = new struct TreeNode(elems[start]);
    if (node->val > (*root)->val) {
        node->left = *root;
        *root = node;
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = node;
        } else {
            struct TreeNode* temp = *root;
            while (temp->right != NULL && temp->right->val > node->val) {
               temp = temp->right; 
            }

            if (temp->right == NULL) {
                temp->right = node;
            }

            if (temp->right->val < node->val) {
                node->right = temp->right;
                temp->right = node;
            }
        }
    }
    maxBinaryTree(root, elems, start+1, num_of_elems-1);
    return;
}

TreeNode* buildMaxBinaryTree(int elems[], int num_of_elems) {
   
    if (num_of_elems == 0) return NULL; 
    struct TreeNode* root = new struct TreeNode(elems[0]);
    maxBinaryTree(&root, elems, 1, num_of_elems-1);
    return root;
}

void postOrderTraversal(struct TreeNode* node) {

    if (node == NULL) return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->val <<" ";
    return;
}

int main() {

    int elems[] = {3, 2, 1, 0, 5, 6};
    TreeNode* root = buildMaxBinaryTree(elems, 6);
    postOrderTraversal(root);    
    return 0;
}
