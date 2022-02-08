#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


void GetNthNode(Node* head,int n)
{
    int len=0;
    Node* temp = head;

    while (temp!=NULL)
    {
        temp=temp->next;
        len++;
    }

    if (len<n)
    {
        return;
    }

    temp=head;

    for (int i = 1; i < len-n+1; i++)
    {
        /* code */

        temp=temp->next;
    }

    cout<<temp->data;

    return ;
    
    
    
}

void push(Node** head_ref,int data)
{
    Node* new_node = new Node();

    new_node->data=data;

    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

int main()
{
    /* code */

    Node* head = NULL;
 
    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
 
    GetNthNode(head, 4);
    return 0;
}
