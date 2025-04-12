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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int size=0;
        ListNode*temp=head;
        while(temp!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        int group=size/k;  
        ListNode* prevhead=nullptr;
        ListNode* currhead=head;
        ListNode* ans=nullptr;

        for(int i=0;i<group;i++)
        {
            ListNode* prev=nullptr;
            ListNode* curr=currhead;
            ListNode* nextnode=nullptr;
            for(int j=0;j<k;j++)//reverse k group
            {
                nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;

            }
            if(prevhead==nullptr){ans=prev;}
            else{
                prevhead->next=prev;
            }
            prevhead=currhead;
            currhead=curr;
        }
        prevhead->next=currhead;
  return ans;
       
    }
};