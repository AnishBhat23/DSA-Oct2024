#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = temp;
    
    if(temp == nullptr || temp->next == nullptr)
    {
        return head;
    }

    while(temp != nullptr)
    {
        if(temp->next != nullptr)
        {
            while(temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
                if(temp->next == nullptr)
                {
                    break;
                }
            }
        }
        else if(temp->val == prev->val)
        {
            prev->next = nullptr;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

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

void printLL(ListNode* head)
{
    ListNode* temp = head;
    while(temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}



int main()
{
    vector<int> arr = {2, 2, 2, 3, 5 ,8 ,7, 10, 10};

    ListNode* head = convertArr2LL(arr);
    ListNode* ans = deleteDuplicates(head);

    printLL(head);    
}