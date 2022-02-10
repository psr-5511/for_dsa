#include <iostream>
using namespace std;


class Node{

    public:
    int data;

    Node* next;
};

void printMiddle(Node* head)
{
    int count = 0;

    Node* mid = head;

    while (head!=NULL)
    {
        /* code */

        if(count & 1)
            mid=mid->next;
        
        ++count;
        head=head->next;
    }

    if(mid!=NULL)
        cout<<"the element is:  "<<mid->data<<endl;    
}

void push(Node** head_ref,int new_data)
{
    Node* new_node = new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void printList(Node* ptr)
{
    while (ptr != NULL){
    
        cout<<ptr->data<<"-->";
        ptr=ptr->next;

    }

    cout<<"NULL"<<endl;
    
}


int main()
{
    Node* head= NULL;
    int i;

    for ( i = 5 ; i >0; i--)
    {
        /* code */

        push(&head,i);
        printList(head);
        printMiddle(head);


    }
    
    return 0;
}
