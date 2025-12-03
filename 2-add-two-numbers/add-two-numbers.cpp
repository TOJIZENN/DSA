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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        int sum=0;
        ListNode* start=new ListNode(-1);
        ListNode* temp=start;
        while(l1 || l2 ||carry!=0)
        {
          sum=carry;
           if(l1){sum+=l1->val;l1=l1->next;}
           if(l2){sum+=l2->val;l2=l2->next;}
           int x=sum;
             sum=x%10;
             carry=x/10;
           temp->next=new ListNode(sum);
           temp=temp->next;
        }
        return start->next;
    }
};