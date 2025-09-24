/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==nullptr || head->next==nullptr){return nullptr;}
        ListNode* slow=head;
        ListNode* fast=head;
        bool changed=false;
         while (fast != nullptr && fast->next != nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
           if(slow==fast)
           {
            changed=true;
            break;
           }
        }
        if(changed==false){return nullptr;}
       ListNode* start=head;
       while(start!=slow)
       {
        start=start->next;
        slow=slow->next;
       }
        return start;
    }
};