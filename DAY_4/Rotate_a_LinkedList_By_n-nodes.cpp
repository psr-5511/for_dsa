#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* next ; 
    Node* prev ;

    Node(char data) 
    {
        this->data = data;
        prev=NULL;
        next=NULL;

    }
};

void insertAtHead(Node* &head , char data)
{
    Node * n = new Node(data);

    if(head==NULL){
        head = n ;
        return ;
    }

    n-> next = head;

    head -> prev = n ;
    head = n ;
    return ;


}

void insertAtTail(Node* &head , char data)
{
    if(head==NULL){
        insertAtHead(head , data);
        return ;
    }

    Node* temp = head ;

    while(temp->next != NULL)
    {
        temp = temp->next;

    }

    Node* n = new Node(data);

    temp->next = n ; 
    n->prev = temp;

    return ;


}

void display(Node* head)
{
    while (head->next!= NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout <<"NULL"<<endl;
    
}

void RotateByN(Node* &head , int pos)
{
    if(pos==0)
        return;

    Node* temp = head ;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head ;

    head -> prev = temp ;

    int count = 1;

    while(count<=pos)
    {
        head = head->next ;
        temp = temp->next;
        count++;
    }

    temp -> next = NULL;
    head -> prev = NULL;
}
int main() 
{
    Node* head=NULL;
    insertAtTail(head,'a');
    insertAtTail(head,'b');
    insertAtTail(head,'c');
    insertAtTail(head,'d');
    insertAtTail(head,'e');
 
    int n=2;
    cout << "\nBefore Rotation : \n";
    display(head);
    RotateByN(head,n);
    cout << "\nAfter Rotation : \n";
    display(head);
    cout << "\n\n";
    return 0;
}

// time complexity -> O(N)

// space complexity -> O(1)