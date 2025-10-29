#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int lengthOfLL(Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while(temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Insert at end of Doubly Linked List

Node* insertAtEndOfDLL(Node* head, int data)
{
    Node* retHead = head;
    Node* tail = head;

    Node* insNode = new Node(data);

    if(retHead == nullptr)
    {
        return insNode;
    }

    while(tail->next)
    {
        tail = tail->next;
    }

    tail->next = insNode;
    insNode->prev = tail;

    return retHead;
}

// Delete at end of linkedList
Node* deleteAtTail(Node* head)
{
    Node* retHead = head;
    Node* curr = head;
    Node* prev = head;

    if(retHead == nullptr || retHead->next == nullptr)
    {
        if(retHead->next == nullptr)
        {
            delete(curr);
            return nullptr;
        }
        else
        {
            return nullptr;
        }
    }

    while(curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    delete(curr);

    return retHead;
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << "Node-" << temp << " Data-" << temp->data << 
        " Next-" << temp->next << " Prev-" << temp->prev << endl;

        temp = temp->next;
    }
}   

Node* findTail(Node* head)
{
    Node* tail = head;
    while(tail->next)
    {
        tail = tail->next;
    } 
    return tail;
}

Node* reverseDLL(Node* head)
{

    Node* curr = head;
    Node* temp = nullptr;

    if(head == nullptr)
    {
        return nullptr;
    }

    while(curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    
    if(temp)
    {
        head = temp->prev;
    }

    return head;
}

int main()
{

    vector<int> arr = {2, 5 ,8 ,7};

    Node* head = convertArr2DLL(arr);
    Node* ans = insertAtEndOfDLL(head, 10);
    printLL(ans);

    Node* ans2 = deleteAtTail(ans);
    printLL(ans2);

    Node* ans3 = reverseDLL(ans2);
    printLL(ans3);

    cout << endl << "Length of LL: " << lengthOfLL(head);

    return 0;
}