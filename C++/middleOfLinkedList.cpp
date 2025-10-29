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
        cout << "Node-" << temp << " Data-" << temp->data << 
        " Next-" << temp->next << endl;

        temp = temp->next;
    }
}   

// Find middle node, brute force method
Node* middleNode_brute(Node* head) 
{
        
    Node* curr = head;

    if(curr == nullptr)
    {
        return nullptr;
    }

    int count = 0;

    while(curr)
    {
        curr = curr->next;
        count++;
    }

    curr = head;
    int mid = count/2;

    for(int i = 0; i < mid; i++)
    {
        curr = curr->next;
    }

    return curr;
}

// Find middle node, optimized method - Fast and slow pointers
Node* middleNode_optimal(Node* head)
{
    if(!head || head->next == nullptr)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> arr = {2, 5 ,8 ,7};

    Node* head = convertArr2LL(arr);
 
    Node* ans = middleNode_optimal(head);
    printLL(ans);

    return 0;
}