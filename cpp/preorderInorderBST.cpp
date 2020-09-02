
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void get_inorder_subtree(vector<int> inorder, int val, vector<int> *left, vector<int> *right) {

    vector<int>::iterator it = inorder.begin();
    while(*it != val) {
        left->push_back(*it);
        it++;
    }
    it++;
    while(it != inorder.end()) {
        right->push_back(*it);
        it++;
    }
}

void get_preorder_subtree(vector<int> preorder, int val, int num_of_left, vector<int> *left, vector<int> *right) {

    int count = num_of_left;
    vector<int>::iterator it = preorder.begin();

    while(*it == val) ++it;

    while(count > 0) {
        left->push_back(*it);
        it++;
        count--;
    }
    while(it != preorder.end()) {
        right->push_back(*it);
        it++;
    }
}

TreeNode* buildBST(vector<int> preorder, vector<int> inorder) {

    if(preorder.size() == 0 || inorder.size() == 0) return NULL;

    TreeNode* root = new TreeNode(preorder.front());

    vector<int> left_preorder;
    vector<int> left_inorder;
    vector<int> right_preorder;
    vector<int> right_inorder;
    get_inorder_subtree(inorder, root->val, &left_inorder, &right_inorder);
    get_preorder_subtree(preorder, root->val, left_inorder.size(), &left_preorder,& right_preorder);

    root->left = buildBST(left_preorder, left_inorder);
    root->right = buildBST(right_preorder, right_inorder);
    
    return root;
}

void printInorder(TreeNode* root) {

    if(root == NULL) return;

    printInorder(root->left);
    cout << root->val <<" ";
    printInorder(root->right);
}

int main() {
    
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};
    vector<int> preorder_vector(preorder, preorder + sizeof(preorder)/sizeof(int));
    vector<int> inorder_vector(inorder, inorder + sizeof(inorder)/sizeof(int));

    TreeNode* root = buildBST(preorder_vector, inorder_vector);
    printInorder(root);
    cout << endl;

    return 0;
}
