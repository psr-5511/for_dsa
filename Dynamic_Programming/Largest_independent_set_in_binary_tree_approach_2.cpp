#include<iostream>

using namespace std;

// a utility function to find max of two integers
int max(int x, int y)
{
    return (x>y) ? x : y;
}

class node{
    public:
    int data;
    int liss;
    node* left,*right;
};

// a memoiztion function returns size of the largest independent set in a given binary tree
int LISS(node* root)
{
    if(root==NULL)
        return 0;
    if(root->liss)
        return root->liss;
    
    if(root->left==NULL && root->right==NULL)
        return root->liss=1;

    // calculate the size excluding the current node 
    int liss_excl=LISS(root->left) + LISS(root->right);

    // calculate the size including the current node
    int liss_incl =1 ;
    if(root->left)
        liss_incl+=LISS(root->left->left) + LISS(root->left->right);
    if(root->right)
        liss_incl+=LISS(root->right->left) + LISS(root->right->right);
    
    // maximum of the two sizes is LISS , store it for future uses .
    root->liss= max(liss_excl,liss_incl);

    return root->liss;

}
node* newNode(int data) {
    node* temp = new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    temp->liss=0;
    return temp;
}

int main()
{
    node* root = newNode(20);
    root->left= newNode(8);
    root->left->left= newNode(4);
    root->left->right= newNode(12);
    root->left->right->left= newNode(10);
    root->left->right->right= newNode(14);
    root->right= newNode(22);
    root->right->right=newNode(25);

    cout<<"the size of the largest independent set is:"<<LISS(root);
    return 0;
}

// time complexity ->O(n) , where n is the number of nodes in given binary tree
