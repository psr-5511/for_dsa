#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

// TO insert the data at the head
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    new_node->next = *head_ref;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    new_node->prev = NULL;

    *head_ref = new_node;
}

void insertAfter(Node *prev, int new_data)
{
    if (prev == NULL){
        cout << "Previous node can't be null";
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;

    new_node->next = prev->next;
    prev->next = new_node;
    new_node->prev = prev;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node **head_ref, int new_data)
{
    // 1 .  Allocate node

    Node *new_node = new Node();

    // 2. Put in the data

    new_node->data = new_data;

    // used in step 5

    Node *last = *head_ref;

    // 3. This new node is going to be the last node of the linked list so make next of it as null

    new_node->next = NULL;

    // 4. if the linked list is empty then make the new node as head

    if ((*head_ref) == NULL)
    {
        new_node->prev = NULL;

        (*head_ref) = new_node;
        return;
    }

    // 5. Else traverse till the last node

    while (last->next != NULL)
        last = last->next;

    // 6. change the next of last node

    last->next = new_node;

    // 7. make last node as previous of new node

    new_node->prev = last;
}

void addBefore(Node *next, Node **head_ref, int new_data)
{
    if (next == NULL)
        return;

    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->prev = next->prev;

    next->prev = new_node;

    new_node->next = next;

    if (new_node->prev != NULL)
        new_node->prev->next = new_node;

    if (new_node->prev == NULL)
        (*head_ref) = new_node;
}
void printList(Node *node)
{
    Node *last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}
int main()
{
    Node *head = NULL;

    append(&head, 6);
    push(&head, 7);

    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    addBefore(head->next->next,&head,23);

    printList(head);
    return 0;
}