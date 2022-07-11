#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return (p==q);
            
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

TreeNode * newNode(int data)
{
    TreeNode *node = new TreeNode();
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;

}

int main()
{
     TreeNode * root1 = newNode(1);
     root1 -> left = newNode(2);
  root1 -> right = newNode(3);
  root1 -> right -> left = newNode(4);
  root1 -> right -> right = newNode(5);

   TreeNode * root2 = newNode(1);
  root2 -> left = newNode(2);
  root2 -> right = newNode(3);
  root2 -> right -> left = newNode(4);
    root2 -> right -> right = newNode(5);


    Solution obj ;
  if (obj.isSameTree(root1, root2))
    cout << "Two Trees are identical";
  else cout << "Two trees are non-identical";
    return 0;
}