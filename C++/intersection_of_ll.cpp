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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* itr1 = headA;
    ListNode* itr2 = headB;

    while(itr1 != itr2)
    {
        itr1 = itr1 == NULL ? headB : itr1->next;
        itr2 = itr2 == NULL ? headA : itr2->next;
    }
    
    return itr1;
}

int main()
{
    vector<int> arr1 = {4, 1, 8, 4, 5};
    vector<int> arr2 = {5, 0, 1};

    ListNode* headA = convertArr2LL(arr1);
    ListNode* headB = convertArr2LL(arr2);

    ListNode* ans = getIntersectionNode(headA, headB);

    if(ans != nullptr)
    {
        cout << "Intersection Node is : " << ans->val << endl;
    }
    else
    {
        cout << "No Intersection Node" << endl;
    }

}