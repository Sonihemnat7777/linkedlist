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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;

            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        {
            // non empty list
            // assuming that the element is presernt in the list

            Node *curr = tail;
            while (curr->data != element)
            {
                curr = curr->next;
            }
            // element found -> current represent the element
            Node *temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    do
    {

        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty ,please check again" << endl;
        return;
    }
    else
    {
        // non empty
        // assuming that "values" is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NUL  L;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 6, 9);
    insertNode(tail, 7, 8);
    insertNode(tail, 6, 10);
    insertNode(tail, 9, 15);
    print(tail);
    deleteNode(tail, 10);
    print(tail);

    return 0;
}