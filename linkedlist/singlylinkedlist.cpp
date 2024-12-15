#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node *&head, int data)
{
    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(Node *&head, int data, int pos, Node *&tail)
{
    Node *temp = head;
    int cnt = 1;

    if (pos == 1)
    {
        insertAtHead(head, data);
    }
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)

    {
        // inster at tail
        insertAtTail(tail, data);
    }
    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        // deleting first node
        Node *temp = head;
        head = head->next;
        // memory free start index
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middel or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    // head pointed to NODE1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 111);
    print(head);
    insertAtTail(tail, 123);
    print(head);
    insertAtTail(tail, 16);
    insertAtHead(head, 18);
    print(head);
    insertAtPosition(head, 112, 3, tail);
    print(head);
    deleteNode(1, head);
    print(head);

    return 0;
}