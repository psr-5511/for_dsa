#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
        
    }


};



class Llist{
    public:
    Node* head;

    Llist()
    {
        head=NULL;
    }


    void insertAtBegin(int val)
    {
        Node* new_node = new Node(val);
        new_node->next=head;

        head=new_node;
    }


    void nThFromEnd(int n)
    {
        Node* main_ptr = head;

        Node* ref_ptr = head;

        if (head==NULL)
        {
            cout<<"The linked list is empty."<<endl;
        }

        for (int i = 1; i < n; i++)
        {
            ref_ptr=ref_ptr->next;
            if (ref_ptr==NULL)
            {
                cout<<n<<"is greater than the number of nodes in the list";
                cout<<endl;

                return;
            }
            
        }


        while (ref_ptr!= NULL && ref_ptr->next!= NULL)
        {
            ref_ptr=ref_ptr->next;
            main_ptr=main_ptr->next;
        }

        cout <<"Node no.    "<<n<<"from last is:    "<<main_ptr->data<<endl;
              
        
    }


    void display()
    {
        Node* temp = head;

        while (temp!= NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
    }
};
int main()
{
    /* code */
    Llist ll;

    for (int i = 60; i>=10; i-=10)
    {
        /* code */

        ll.insertAtBegin(i);
    }


        ll.display();


     for (int i = 1; i <= 7; i++)
        ll.nThFromEnd(i);
    
    
    return 0;
}
