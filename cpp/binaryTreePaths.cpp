
#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    bool visited;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), visited(false), left(NULL), right(NULL) {}
};

string convert_vector_to_string(vector<int> path) {
    
    vector<int>::iterator itr;
    int size = path.size();
    string path_str;

    for (itr = path.begin(); itr != path.end(); itr++) {
        path_str += to_string(*itr);
        if (*itr != path.back())
           path_str += "->"; 
    }
    cout << "Path: "<< path_str << " is found."<< endl;
    return path_str;
}

void print_vector_content(vector<int> path) {

    vector<int>::iterator itr;
    for(itr = path.begin(); itr != path.end(); itr++)
        cout << *itr << " ";
    cout << endl;
}

vector<string> findAllPaths(TreeNode* node) {

    TreeNode* x;
    vector<string> paths;
    vector<int> path;
    string path_str;
    stack<TreeNode*> nodeStack;

    nodeStack.push(node);
    path.push_back(node->val);
    while (!nodeStack.empty()) {
        
        x = nodeStack.top();

        if (x->left == NULL && x->right == NULL) {
            x->visited = true; 
            print_vector_content(path);
            path_str = convert_vector_to_string(path);
            paths.push_back(path_str);
        }
        
        if (x->left == NULL && (x->right != NULL && x->right->visited)) {
            x->visited = true;
        }
        
        if ((x->left != NULL && x->left->visited) && x->right == NULL) {
            x->visited = true;
        }
        
        if ((x->left != NULL && x->left->visited) && (x->right != NULL &&x->right->visited)) {
            x->visited = true;
        }

        if (x->visited) {
            nodeStack.pop();
            path.pop_back();
        } else {

            if (x->left != NULL && !x->left->visited) {
                nodeStack.push(x->left);
                path.push_back(x->left->val);
                continue;
            }

            if (x->right != NULL && !x->right->visited) {
                nodeStack.push(x->right);
                path.push_back(x->right->val);
                continue;
            }
        }
    }
    return paths;
}

int main() {

    TreeNode* root = new struct TreeNode(1);
    root->left = new struct TreeNode(2);
    root->right = new struct TreeNode(3);
    root->left->right = new struct TreeNode(5);

    vector<string>::iterator itr;
    cout << "Calling findAllPaths" << endl;
    vector<string> paths = findAllPaths(root);
    cout << "Completed findAllPaths" << endl;
    cout << "Number of paths: " << paths.size() << endl;
    for(itr = paths.begin(); itr != paths.end(); itr++)
        cout << *itr << endl;

    return 0;
}
