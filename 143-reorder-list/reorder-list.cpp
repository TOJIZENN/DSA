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
    int size(ListNode* head) {
        int i=0;
        while (head != nullptr) {
            i++;
            head = head->next;
        }
        return i;
    }

    ListNode* reverse(ListNode* tem) {
        ListNode* curr = tem;
        ListNode* forw;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int n = size(head);
        if(n==1 || n==0){return;}
        int mid = n / 2 - 1;
        int x=mid;
        while (mid--) {
            temp = temp->next;
        }
        ListNode* cn = reverse(temp->next);
        temp->next = nullptr;
        int i=0;
        ListNode* co=head;
        ListNode* nx;
        ListNode* t;
        while(i<=x)
        {
            if(i==0)
            {
             nx=co->next;
             co->next=cn;
             t=cn;
             cn=cn->next;
             co=nx;
            }
            else if(i==x)
            {
             co->next=cn;
             t->next=co;
            }
            else
            {
             nx=co->next;
             co->next=cn;
             t->next=co;
             t=cn;
             co=nx;
             cn=cn->next;
            }
            i++;
        }
    }
};