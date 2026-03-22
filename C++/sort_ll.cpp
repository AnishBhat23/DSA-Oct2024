#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int data1, ListNode* next1)
    {
        val = data1;
        next = next1;
    }

    public:
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }
};

ListNode* convertArr2LL(vector<int> &arr)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}   

ListNode* findMiddle(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* mergeSortedLists(ListNode* left, ListNode* right)
{
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(left != nullptr && right != nullptr)
    {
        if(left->val <= right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if(left != nullptr)
    {
        temp->next = left;
    }

    if(right != nullptr)
    {
        temp->next = right;
    }

    return dummyNode->next;
}

ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* middle = findMiddle(head);

    ListNode* right = middle->next;
    middle->next = nullptr;

    ListNode* left = head;

    ListNode* a = sortList(left);
    ListNode* b = sortList(right);

    return mergeSortedLists(a, b);
}


int main()
{
    vector<int> arr = {2, 5 ,8 ,7, 10};

    ListNode* head = convertArr2LL(arr);

    ListNode* newHead = sortList(head);

    ListNode* temp = newHead;
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

}