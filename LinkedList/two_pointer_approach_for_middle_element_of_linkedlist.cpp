#include<iostream>

using namespace std;
class Node {
    public:
    int data;
    Node* next;

};


class NodeOperation{
    public:

    void push(Node** head_ref,int data)
    {
        Node* new_node = new Node;

        new_node->data = data;

        new_node->next = *head_ref;

        *head_ref = new_node;

    }

    void printNode(Node* head)
    {
        while (head!=NULL)
        {
            cout<<head->data<<"-->";
            head=head->next;
        }

        cout<<"NULL"<<endl;
        
    }


    void printMiddle(Node* head)
    {
        Node* slow_ptr = head;
        Node* fast_ptr = head;

        if (head!=NULL)
        {
            while (fast_ptr!= NULL && fast_ptr->next!= NULL)
            {
                fast_ptr=fast_ptr->next->next;
                slow_ptr=slow_ptr->next;
            }

            cout <<"The middle element of the list is ["<<slow_ptr->data<<"]"<<endl;
            
        }
        
    }
};

int main()
{
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    for (int  i = 6; i>0; i--)
    {
        temp->push(&head,i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
    
    return 0;
}
