#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left =NULL;
    newNode->right =NULL;

    return newNode;
}


// an iterative process to print the preorder traversal of a binary tree
void iterativePreOrder(Node* root){
    // Base case 
    if(root==NULL) return; 

    stack<Node*> nodeStack;

    nodeStack.push(root);


    while(nodeStack.empty()==false){
        Node* node = nodeStack.top();
        cout<<"->"<<node->data;
        nodeStack.pop();

        if(node->right){
            nodeStack.push(node->right);
        }
        if(node->left){
            nodeStack.push(node->left);
        }
    }
}
int main()
{
    Node* root =newNode(10);

    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(2);
    iterativePreOrder(root);

    return 0;
}