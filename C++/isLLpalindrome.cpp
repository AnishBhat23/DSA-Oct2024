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

Node* reverseLinkedList(Node* head)
{
    if (head == NULL || head->next == NULL) 
    {
        return head;  
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;

    front->next = head;
    head->next = nullptr;

    return newHead;
}

bool isPalindrome(Node* head) {

    if(head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLinkedList(slow->next);

    Node* start1 = head;
    Node* start2 = newHead;

    while(start2 != nullptr)
    {
        if(start1->data != start2->data)
        {
            reverseLinkedList(newHead);
            return false;
        }
        
        start1 = start1->next;
        start2 = start2->next;
    }

    reverseLinkedList(newHead);
    
    return true;
}


int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    Node* head = convertArr2LL(arr);

    bool ans = isPalindrome(head);

    cout << "Is Palindrome: " << ans << endl;

}