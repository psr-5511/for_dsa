#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

class TreeNode{
public:
	int val ; 
	TreeNode* left , *right;
};


class Solution{
public:

	void recursive(TreeNode* root , int level , vector<int> &res)
	{
		if (root == NULL) return ;

		if(res.size() ==level) res.push_back(root->val);

		recursive(root->right , level + 1, res);
		recursive(root->left , level + 1, res);
	}

	vector<int> rightSideViewOfBinaryTree(TreeNode* root)
	{
		vector<int> res ;

		recursive( root , 0 , res);

		return res ;
	}
};

TreeNode* newNode(int data)
{
	TreeNode* node = new TreeNode();

	node->val = data;
	node->left = NULL;

	node->right = NULL;

	return node;
}
int main()
{
	TreeNode* root = newNode(1);

	root->left = newNode(2);

	root->right = newNode(3);

	root->left->left = newNode(4);

	root->left->right = newNode(5);

	root->left->right->left = newNode(6);

	root->right->right = newNode(7);

	Solution obj ;

	vector<int> temp =obj.rightSideViewOfBinaryTree(root);

	for(auto x : temp){
		cout << x << " ";
	}

	
	return 0;
}