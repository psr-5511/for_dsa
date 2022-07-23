#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* next ;
};

Node* newNode(int data);

Node* sortList(Node* head)
{

    if(!head || !(head->next))
        return head ;

    Node* zeroD = newNode(0);
    Node* oneD = newNode(0);
    Node* twoD = newNode(0);

    Node* zero = zeroD, *one = oneD , *two = twoD;

    Node* curr = head ;

    while(curr)
    {
        if(curr->data == 0)
        {
            zero->next = curr;
            zero = zero-> next;
        }

        else if(curr->data == 1)
        {
            one->next = curr;
            one = one-> next;
        }

        else
        {
            two->next = curr;
            two = two->next;
        }

        curr = curr->next;
    }

    zero-> next = (oneD->next) ? (oneD->next):(twoD->next);

    one->next = twoD->next;

    two-> next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

Node* newNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
}

void printList(Node* node)
{
    while (node!= NULL)
    {
        cout<<node->data;
        node= node->next;
    }

    cout<<"\n";
    
}

int main() 
{
    Node* head = newNode(1);

    head->next = newNode(2);
    head->next ->next = newNode(0);

    head->next->next->next = newNode(1);

    cout<<"Linked list before sorting\n";
    printList(head);

    head = sortList(head);

    cout<<"Linked list after sorting\n";

    printList(head);
    return 0;
}