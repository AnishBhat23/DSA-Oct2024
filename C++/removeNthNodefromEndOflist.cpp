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
   
Node* removeNthFromEnd(Node* head, int n) {
    Node* p1 = head;
    Node* p2 = head;
    float count = 1;

    if(head->next == nullptr && n == 1)
    {
        return nullptr;
    }
    if(head->next->next == nullptr)
    {
        if(n==1)
        {
            head->next = nullptr;
            return head;
        }
        else if(n==2)
        {
            head = head->next;
            return head;
        }
    }

    while(p2 != nullptr && p2->next != nullptr && p2->next->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        count++;
    }

    if(p2->next == nullptr)
    {
        //odd
        count = (count*2)-1;
    }
    else if(p2->next->next == nullptr)
    {
        //even
        count = count*2;
    }

    int target = (count-n);
    if(target == 0)
    {
        head = head->next;
        return head;
    }

    cout << "MidPoint " << p1->data << endl;
    cout << "Target " << target << endl; 
    cout << "Count " << count << endl; 

    if(target > (ceil(float(count/2))-1))
    {
        int startItr = ceil(float(count/2))-1;
        cout << "startItr " << startItr << endl; 
        Node* start = p1;
        Node* prev = start;
        while(startItr != target)
        {
            prev = start;
            start = start->next;
            startItr++;
        }
        prev->next = start->next;
    }
    else
    {
        int startItr = 0;
        Node* start = head;
        Node* prev = start;
        while(startItr != target)
        {
            prev = start;
            start = start->next;
            startItr++;
        }
        prev->next = start->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    Node* head = convertArr2LL(arr);

    Node* newHead = removeNthFromEnd(head, 2);

    Node* temp = newHead;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}