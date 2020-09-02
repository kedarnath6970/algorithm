
#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* nextRight;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(struct TreeNode* node) {

    if (node == NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight) return lheight+1;
        else return rheight+1;
    }
}

void printGivenLevel(struct TreeNode* node, int level) {

    if (node == NULL) return;

    if (level == 1){
        cout << node->val << " -> ";
        if (node->nextRight == NULL)
            cout << "NULL" << endl;
    }
    else if (level > 1) {
        printGivenLevel(node->left, level-1);
        printGivenLevel(node->right, level-1);
    }
}

void enqueueLevelNode(struct TreeNode* node, int level, int original_level, queue<struct TreeNode*>& nq, queue<int>& lq) {

    if (node == NULL) return;
    
    if (level == 1) {
        nq.push(node);
        lq.push(original_level);
    }
    else if (level > 1) {
        enqueueLevelNode(node->left, level-1, original_level, nq, lq);
        enqueueLevelNode(node->right, level-1, original_level, nq, lq);
    }
}

void levelOrderTraversal(struct TreeNode* root, int set, queue<struct TreeNode*>& nq, queue<int>& lq) {

    int h = height(root);
    for (int i=1; i<=h; i++) {
        if (set == 1) 
            enqueueLevelNode(root, i, i, nq, lq);
        else
            printGivenLevel(root, i);
    }
}

void setNextRightPointer(queue<struct TreeNode*> nq, queue<int> lq) {
    struct TreeNode* prev_node;
    struct TreeNode* cur_node;
    int prev_level, cur_level;
    
    cout << "Size of nq: " << nq.size() << endl;
    cout << "Size of lq: " << lq.size() << endl;

    prev_node = nq.front();
    prev_level = lq.front();
    nq.pop();
    lq.pop();
    while (nq.size() > 0) {
        cur_node = nq.front();
        cur_level = lq.front();
        nq.pop();
        lq.pop();
        cout << "current node: " << cur_node->val << endl;
        if (prev_level != cur_level)
            prev_node->nextRight = NULL;
        else
            prev_node->nextRight = cur_node;

        prev_node = cur_node;
        prev_level = cur_level;
    }

    if (prev_node != NULL)
        prev_node->nextRight = NULL;
}

void setNextRightPointerSimple(struct TreeNode* node) {

    if (node == NULL) return;

    if (node->right != NULL) {
        if (node->nextRight == NULL)
           node->right->nextRight = NULL;
        else {
            if (node->nextRight->left != NULL)
                node->right->nextRight = node->nextRight->left;
            else if (node->nextRight->right != NULL)
                node->right->nextRight = node->nextRight->right;
        }

        if (node->left != NULL)
            node->left->nextRight = node->right;
    }
    setNextRightPointerSimple(node->left);
    setNextRightPointerSimple(node->right);
}

int main() {

    struct TreeNode* root = new struct TreeNode(1);
    root->left = new struct TreeNode(2);
    root->right = new struct TreeNode(3);
    root->left->left = new struct TreeNode(4);
    root->left->right = new struct TreeNode(5);
    //root->right->left = new struct TreeNode(6);
    root->right->right = new struct TreeNode(7);

    root->nextRight = NULL;
    queue<struct TreeNode*> nq;
    queue<int> lq;
    //levelOrderTraversal(root, 1, nq, lq);
    //setNextRightPointer(nq, lq);
    //levelOrderTraversal(root, 0, nq, lq);
    setNextRightPointerSimple(root);
    levelOrderTraversal(root, 0, nq, lq);
    cout << "Completed everything successfully." << endl;

    return 0;
}
