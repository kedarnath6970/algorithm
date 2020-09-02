
#include <iostream>

using namespace std;


class Node {

    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {}

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
                Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomRight = _bottomRight;
            bottomLeft = _bottomLeft;
        }
};

Node* intersection(Node* quadTree1, Node* quadTree2) {
    bool val;
    Node* topLeft, *topRight, *bottomLeft, *bottomRight;;

    if (quadTree1->isLeaf && quadTree1->val)
        return new Node(quadTree1->val, true, NULL, NULL, NULL, NULL);

    if (quadTree2->isLeaf && quadTree2->val)
        return new Node(quadTree2->val, true, NULL, NULL, NULL, NULL);

    if (quadTree1->isLeaf && quadTree2->isLeaf) {
        return new Node(false, true, NULL, NULL, NULL, NULL);
    }

    topLeft = intersection(quadTree1->topLeft, quadTree2->topLeft);
    topRight = intersection(quadTree1->topRight, quadTree2->topRight);
    bottomLeft = intersection(quadTree1->bottomLeft, quadTree2->bottomLeft);
    bottomRight = intersection(quadTree1->bottomRight, quadTree2->bottomRight);
    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
}

int main() {

    Node *A_topLeft, *A_topRight, *A_bottomLeft, *A_bottomRight;
    A_topLeft = new Node(true, true, NULL, NULL, NULL, NULL);
    A_topRight = new Node(true, true, NULL, NULL, NULL, NULL);
    A_bottomLeft = new Node(false, true, NULL, NULL, NULL, NULL);
    A_bottomRight = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* A = new Node(false, false, A_topLeft, A_topRight, A_bottomLeft, A_bottomRight);

    Node *B_topLeft, *B_topRight, *B_bottomLeft, *B_bottomRight;
    B_topLeft = new Node(true, true, NULL, NULL, NULL, NULL);
    B_topRight = new Node(false, false,
            new Node(false, true, NULL, NULL, NULL, NULL),
            new Node(false, true, NULL, NULL, NULL, NULL),
            new Node(true, true, NULL, NULL, NULL, NULL),
            new Node(true, true, NULL, NULL, NULL, NULL));
    B_bottomLeft = new Node(true, true, NULL, NULL, NULL, NULL);
    B_bottomRight = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* B = new Node(false, false, B_topLeft, B_topRight, B_bottomLeft, B_bottomRight);

    Node* C = intersection(A, B);
    cout <<"TopLeft of C: "<< C->topLeft->val << endl;
    cout <<"TopRight of C: " << C->topRight->val << endl;
    cout <<"BottomLeft of C: " << C->bottomLeft->val << endl;
    cout <<"BottomRight of C: "<< C->bottomRight->val << endl;

    return 0;
}
