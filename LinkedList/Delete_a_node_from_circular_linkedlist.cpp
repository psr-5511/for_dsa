#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    Node *ptr1 = new Node();

    ptr1->data = new_data;
    ptr1->next = *head_ref;

    // if linked list is not null then set the next of last node
    if (*head_ref != NULL)
    {
        // find the node before the head and update the next of it
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }

    else
        ptr1->next = ptr1; // for the first node

    *head_ref = ptr1;
}

void print(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data<<" ";
            temp = temp->next;
        } while (temp!=head);
        
    }

    cout<<endl;
}

void deletekey(Node **head,int key){
    // if linked list is empty 
    if(*head==NULL)
        return;
    
    // if the list contains only a single node 
    if((*head)->data == key && (*head)->next==*head)
    {
        free(*head);
        *head==NULL;
        return;
    }

    // if head is to be deleted 
    Node* last = *head, *d;
    if((*head)->data == key)
    {
        // find the last node of the list
        while(last->next!=*head)
            last = last->next;
        
        // Point last node to the next of head i.e. to the second node of linked list 
        last->next = (*head)->next;
        free(*head);
        (*head) = last->next;
    }

    // either the node to be deleted is not found or the end of the list is not reached 

    while(last->next!=(*head) && last->next->data!=key) 
        last = last->next;

    // if the node to be deleted was found 

    if(last->next->data==key)
    {
        (d) = last->next;
        last->next = (d )-> next;
        free(d);

    }

    else cout << "No Such key Found" << endl;
}

int main()
{
     Node* head = NULL;
  
    /* Created linked list will be 2->5->7->8->10 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
  
    cout << "List Before Deletion: ";
    print(head);
  
    deletekey(&head, 7);
  
    cout << "List After Deletion: ";
    print(head);
    return 0;
}