#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; //
    Node* next; //
    Node* prev; //

};

// Function to delete a node from linkd list 
// *head_ref - >  is the pointer to the head node 
// del -> is the pointer to the node which we have to delete

void deleteNode(Node** head_ref,Node* del)
{
    // Base case

    if(*head_ref==NULL || del == NULL) return;

    // if the node to be deleted is the head node

    if(*head_ref==del)  (*head_ref) = del->next;

    // Change the next only if the node to be deleted is not the last node 

    if(del->next!=NULL)
        del->next->prev = del->prev;
    // Change the prev only if the node to be deleted is not the first node

    if(del->prev!=NULL)
        del->prev->next = del->next;

    // Finally free the memory occupied by del 

    free(del);

    return;
}


void push(Node** head_ref,int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if((*head_ref)!=NULL) 
        (*head_ref)->prev = new_node;

    (*head_ref) =new_node;

}

void printList(Node* node)
{
    while(node!=NULL)
    {
        cout <<node->data<<" ";
        node=node->next;
    }
}
int main() 
{

    Node* head = NULL; 
  
    /* Let us create the doubly linked list 10<->8<->4<->2 */
    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 
  
    cout << "Original Linked list "; 
    printList(head); 


     /* delete nodes from the doubly linked list */
    deleteNode(&head, head); /*delete first node*/
    deleteNode(&head, head->next); /*delete middle node*/
    deleteNode(&head, head->next); /*delete last node*/
  
    /* Modified linked list will be NULL<-8->NULL */
    cout << "\nModified Linked list "; 
    printList(head); 


    return 0;
}



// time complexity - O(1)

// space complexity - O(1)