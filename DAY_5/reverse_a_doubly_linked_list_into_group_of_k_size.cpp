// this is the recursive implementation


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data; //
    Node* next , *prev; //

};

// Function to get a new node 
Node* getNode(int data)
{
    // allocate space
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void push(Node** head_ref,Node* new_node)
{
    // since we are adding at the beginning prev is null
    new_node->prev = NULL;

    // link the old list off the new node 
    new_node->next = (*head_ref);

    // change prev of head node to new node 

    if((*head_ref)!=NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to th new node

    (*head_ref) = new_node;


}

// function to reverse a doubly linked list 
//  in groups of given size

Node* revListInGroupOfGivenSize(Node* head , int k)

{
    Node* current = head ;

    Node* next = NULL;

    Node* newHead = NULL;

    int count = 0;

    // reversing the current group of k or less than k nodes by adding them at the beginning of list 'newHead'

    while(current!=NULL && count < k)
    {
        next = current->next ;

        push(&newHead , current);

        current = next ;

        count++;
    }

    // if next group exists then making the desired adjustments in the link 

    if(next!=NULL)
    {
        head -> next = revListInGroupOfGivenSize(next,k);

        head->next->prev = head;
    }

    newHead->prev =NULL;

    return newHead;
}


void printList(Node* head)

{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() 
{
    Node* head = NULL;

    push(&head,getNode(2));
    push(&head,getNode(4));
    push(&head,getNode(8));
    push(&head,getNode(10));

    int k = 2;

    cout<<"Original List : ";

    printList(head);

    // reverse doubly linked list in groups of size k 

    head = revListInGroupOfGivenSize(head,k);

    cout<<"\nModified list:";

    printList(head);
    return 0;
}


// time complexity - O(n)

// space complexity -> O(1)