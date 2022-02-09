#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next= NULL;
};

void printNthFromLast(Node* head,int n)
{
    static int count=0;
   

    if (head==NULL)
    {
        return;
    }

    printNthFromLast(head->next,n);

    if (++count== n)
    {
        cout<<head->data;
    }
    
    
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

    Node* head= NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printNthFromLast(head, 4);   



    return 0;
}





