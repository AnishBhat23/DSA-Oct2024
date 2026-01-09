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

bool hasCycle(Node *head) {
        Node *slow = head;
        Node *fast = head;

        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                return true;
            }

        }

        return false;
    }

int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    Node* head = convertArr2LL(arr);

    bool ans = hasCycle(head);

    cout << "Cycle Present: " << ans << endl;

}