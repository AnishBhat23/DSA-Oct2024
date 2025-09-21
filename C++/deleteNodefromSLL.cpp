#include<bits/stdc++.h>
using namespace std;

/*
    There is a singly-linked list head and we want to delete a node node in it.

    You are given the node to be deleted node. You will not be given access to the first node of head.

    All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

    Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.
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

void deleteNode(Node* node) 
{
    Node *temp = node->next;
    node->data = node->next->data;
    node->next= node->next->next;
    delete(temp);   
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
    deleteNode(head->next);

}