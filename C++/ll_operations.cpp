#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head)
{
    Node* temp = head;

    head = head->next;
    delete temp;

    return head;
}

Node* insertHead(Node* head, int data)
{
    Node* temp = new Node(data);

    temp->next = head->next;
    head = temp;

    return head;
}

void deleteTail(Node* head)
{
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    delete (temp->next);
}

Node* insertatPos(Node* head, int data, int pos)
{
    Node* temp = new Node(data);
    Node* itr = head;
    Node* ans = nullptr;

    if(pos == 1)
    {
        ans = insertHead(head,data);
        return ans;
    }

    int count = 1;
    while(count < pos)
    {
        if(itr->next == nullptr)
        {
            break;
        }
        itr = itr->next;
        count++;
    }

    if(itr->next != nullptr)
    {
        temp->next = itr->next;
        itr->next = temp;
    } 
    else
    {
        itr->next = temp;
    }
    
    ans = head;
    return head;
}

Node* deleteAtPos(Node* head, int pos)
{
    Node* itr = head;
    Node* prevItr = head;
    Node* ans = nullptr;

    if(pos == 1)
    {
        ans = deleteHead(head);
        return ans;
    }

    int count = 1;
    while(count < pos)
    {
        if(itr->next == nullptr)
        {
            break;
        }
        prevItr = itr;
        itr = itr->next;
        count++;
    }

    if(itr->next != nullptr)
    {
        prevItr->next = itr->next;
        delete (itr);
    } 
    else
    {
        delete (itr);
    }
    
    ans = head;
    return ans;
}

int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    Node* head = convertArr2LL(arr);

    //deleteTail(head);

    //insertatPos(head, 10, 5);
    
    insertatPos(head, 12, 5);

    insertatPos(head, 15, 5);

    printLL(head);

}