#include<bits/stdc++.h>
using namespace std;

/*
    Given the head of a linked list and an integer val, 
    remove all the nodes of the linked list that has Node.val == val, 
    and return the new head.
*/

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

Node* removeElements(Node* head, int val) {
    // Dummy node to handle cases where head itself needs to be removed
    Node* dummy = new Node(-1);
    dummy->next = head;

    Node* curr = dummy;
    while (curr->next != nullptr) {
        if (curr->next->data == val) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp; // free memory
        } else {
            curr = curr->next;
        }
    }

    head = dummy->next;
    delete dummy; // clean up dummy node
    return head;
}

int main()
{
    int n1;
    cin >> n1;
    
    vector<int> arr1;
    for(int i=0;i<n1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    Node* head = convertArr2LL(arr1);

}