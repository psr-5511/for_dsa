#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};
vector<int> postOrderTrav(Node *cur)
{
    vector<int> postOrder;

    if (cur == NULL)
        return postOrder;

    stack<Node *> st;

    while (!st.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }

        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }

            else
            {
                cur = temp;
            }
        }
    }

    return postOrder;
}

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    Node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> postOrder;
    postOrder = postOrderTrav(root);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
    return 0;
}


// Time complexity -> O(n)
// Space complexity -> O(n)