
#include <iostream>
#include <utility>
#include <stack>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x): val(x), children(0) {}
};

vector<int> postorderIterative(TreeNode* root) {

    vector<int> nodeVal;
   
    if (root == NULL) return nodeVal;
    
    struct TreeNode* node = NULL;
    typedef pair<TreeNode*, bool> nodeInfo;
    stack<nodeInfo> nodeStack;
    nodeStack.push(nodeInfo(root, false));

    while(!nodeStack.empty()) {
        nodeInfo& x = nodeStack.top();
        
        if (x.second) {
            nodeVal.push_back(x.first->val);
            nodeStack.pop();
        } else {
            x.second = true;
            vector<TreeNode*> children = x.first->children;
            vector<TreeNode*>::iterator itr;
            for (itr = children.begin(); itr != children.end(); itr++)
                nodeStack.push(nodeInfo(*itr, false));
        }
    }
    return nodeVal;
}

void printPostorder(vector<int> postorder) {
    
    vector<int>::iterator itr;
    for(itr = postorder.begin(); itr != postorder.end(); itr++)
        cout << *itr << " ";
    cout << endl;
}

int main() {

    struct TreeNode* root = new struct TreeNode(1);
    struct TreeNode* rootLeft = new struct TreeNode(3);
    struct TreeNode* rootMiddle = new struct TreeNode(2);
    struct TreeNode* rootRight = new struct TreeNode(4);

    rootLeft->children.push_back(new struct TreeNode(6));
    rootLeft->children.push_back(new struct TreeNode(5));
    
    root->children.push_back(rootRight);
    root->children.push_back(rootMiddle);
    root->children.push_back(rootLeft);

    cout << "Calling preorderIterative"<<endl;
    vector<int> preorder = postorderIterative(root);

    printPostorder(preorder);
    cout << "Completed postorderIterative"<<endl;
}
