#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertAtHead(Node * &head, int data)
{
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
        
}
void insertAtTail(Node * &tail,int data){
if(tail==NULL)
{
    Node *temp=new Node(data);
    tail=temp;
}
else{
    Node *temp=new Node(data);
   temp->next=tail->next;
    tail->next=temp;
    tail=temp;
}
}
void print(Node * head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    if(temp==NULL) cout<<"NULL";
}
int main()
{
    Node *node1 = new Node (10);
    Node *head = node1;
    Node *tail=node1;
    insertAtHead(head,11);
    insertAtTail(tail,15);
    insertAtTail(tail,18);
    insertAtHead(head,22);
    insertAtHead(head,12);
    insertAtTail(tail,17);
    insertAtTail(tail,19);
    insertAtHead(head,25);
    print(head);
    

    return 0;
}