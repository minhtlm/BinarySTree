#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};
void Init(Node *&Tree) {
    Tree = NULL;
}
void Insert(Node *pRoot, int x) {
    if(pRoot == NULL) {
        Node *q;
        q = new Node;
        q->data = x;
        q->pLeft = q->pRight = NULL;
        pRoot = q;
    }
    else {
        if(x < pRoot->data)
        Insert(pRoot->pLeft, x);
        else if(x > pRoot->data)
        Insert(pRoot->pRight, x);
    }
}
void CreateTree(Node *&pRoot) {
    int data;
    do {
        cout << "Nhap vao du lieu, -1 de ket thuc: ";
        cin >> data;
        if(data == -1) break;
        Insert(pRoot, data);
    } while (1);    
}
void NLR(Node *pTree) {
    if(pTree != NULL) {
        cout << pTree->data;
        NLR(pTree->pLeft);
        NLR(pTree->pRight);
    }
}
Node* Search(Node* pRoot, int x) {
    if(pRoot == NULL) return NULL;
    if(x < pRoot->data)
        Search(pRoot->pLeft, x);
    else
    if(x > pRoot->data)
        Search(pRoot->pRight, x);
    else return pRoot;
}
int Height(Node* pNode) {
    if(pNode == NULL) return 0;
    int HL, HR;
    HL = Height(pNode->pLeft);
    HR = Height(pNode->pRight);
    if(HL > HR)
        return (1 + HL);
    return (1 + HR);
}

int main() {
    Node *pTree, *p;
    int x;

    Init(pTree);
    CreateTree(pTree);
    NLR(pTree);

}
