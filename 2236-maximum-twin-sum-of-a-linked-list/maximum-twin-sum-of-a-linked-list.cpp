/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* reverseList(ListNode* head)
{
  if(!head || !head->next){return head;}
   ListNode* node=reverseList(head->next);
   head->next->next=head;
   head->next=NULL;
   return node;
}
    int pairSum(ListNode* head) 
    {
     int ans=INT_MIN;
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast!=nullptr && fast->next!=nullptr)
     {
        slow=slow->next;
        fast=fast->next->next;
     }
     ListNode* second=reverseList(slow);
        while(second!=nullptr)
        {
           ans=max(ans,head->val+second->val);
           head=head->next;
           second=second->next;
        }
        return ans;
    }
};