#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next, *prev;
};

void pairSum(Node* head,int x)
{
    Node* first = head;
    Node* second = head;

    while(second->next != NULL)
        second = second->next;
    
    bool found = false;

    while (second->next!=first && first!=second)
    {
        if((first->data + second->data)==x)
        {
            cout<<"("<<first->data<<","<<second->data<<")"<<endl;
            found = true;

            first = first->next;

            second = second->next;
        }

        else
        {
            if((first->data + second->data)<x)
                first = first->next;
            
            else
                second = second->prev;
        }
        
    }

    if(found==false)
        cout<<"No such pair exist";
    
}

void insert(Node ** head,int data)
{
    Node* temp = new Node;

    temp->data = data;

    temp->next = temp->prev = NULL;
    if(!(*head))
        (*head) = temp;
    
    else
    {
        temp ->next = (*head);
        (*head)->prev = temp ; 
        (*head) = temp ;
    }

}
int main() 
{
    Node* head = NULL;

    insert(&head,9);
    insert(&head,8);
    insert(&head,6);
    insert(&head,5);
    insert(&head,4);
    insert(&head,2);
    insert(&head,1);
    
    int x = 7;

    pairSum(head,x);

    return 0;
}


// time complexity - O(n)  
// space complexity -> O(1)