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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    int adder = 0;
    ListNode* temp = new ListNode(0);
    ListNode* ans = temp;
    while(l1!=nullptr || l2!=nullptr || adder)
    {
        int x = l1!=nullptr ? l1->val : 0;
        int y = l2!=nullptr ? l2->val : 0;
        int sum = x + y + adder;
        adder = sum/10;
        ans->next = new ListNode(sum%10);
        ans = ans->next;
        l1 = l1!=nullptr ? l1->next : l1;
        l2 = l2!=nullptr ? l2->next : l2;
    }
    return temp->next;
}

int main()
{
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    ListNode* head1 = convertArr2LL(arr1);
    ListNode* head2 = convertArr2LL(arr2);

    ListNode* ans = addTwoNumbers(head1, head2);

    ListNode* temp = ans;
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}