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

Node* oddEvenList(Node* head) 
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
        return head;
    }

    Node* oddStart = head;
    Node* evenStart = head->next;

    Node* oddTemp = oddStart;
    Node* evenTemp = evenStart;

    while(oddTemp->next->next != nullptr && evenTemp->next->next != nullptr)
    {
        oddTemp->next = oddTemp->next->next;
        evenTemp->next = evenTemp->next->next;

        oddTemp = oddTemp->next;
        evenTemp = evenTemp->next;
    }

    if(oddTemp->next->next == nullptr)
    {
        oddTemp->next = evenStart;
        evenTemp->next = nullptr;
        return head;
    }
    else if(evenTemp->next->next == nullptr)
    {
        oddTemp->next = oddTemp->next->next;
        oddTemp = oddTemp->next;

        oddTemp->next = evenStart;
        evenTemp->next = nullptr;
        return head;
    }
    else
    {
        return head;
    }        
}

int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    Node* head = convertArr2LL(arr);

    Node* newHead = oddEvenList(head);

    Node* temp = newHead;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}