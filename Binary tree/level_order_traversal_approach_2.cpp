#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;


};

void printLevelOrder(Node* root) {
    if(root==NULL)
        return;


    queue<Node*> q;

    q.push(root);

    while(q.empty()==false) {
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();


        if(node->left!=NULL) 
            q.push(node->left);
        if(node->right!=NULL) 
            q.push(node->right);


            
        
    }
}

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){

     Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}