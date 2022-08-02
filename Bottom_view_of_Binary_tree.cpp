#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left , *right;
};


class Solution {

public:

	vector<int> bottomViewOfBinaryTree(Node* root)
	{
		vector<int> ans ;

		if(root == NULL) return ans;

		map<int, int> mpp ;

		queue<pair<Node*,int>> q;

		q.push({root, 0});

		while(!q.empty())
		{
			auto it = q.front();

			q.pop();

			Node* node = it.first;
			int line = it.second;

			mpp[line] = node->data;

			if(node->left != NULL)
				q.push({node->left , line -1 });

			if(node->right!=NULL)
				q.push({node->right , line+1});

		}

		for(auto it : mpp)
			ans.push_back(it.second);

		return ans ; 
	}
};

Node* newNode(int data)
{
	Node* node = new Node();

	node->data = data;
	node->left = NULL;
	node->right = NULL;
}



int main()
{

	Node* root = newNode(1);

	root->left = newNode(2);

	root->right = newNode(3);

	root->left->left = newNode(4);

	root->left->right = newNode(5);

	root->left->right->left = newNode(8);

	root->left->right->right = newNode(9);

	root->right->left = newNode(6);

	root->right->right = newNode(7);


	Solution obj ;

	vector<int> result = obj.bottomViewOfBinaryTree(root);

	for(auto x :result)
		cout<<x<<" ";

	return 0;
}


// time complexity - O(n)

// space complexity - O(n)