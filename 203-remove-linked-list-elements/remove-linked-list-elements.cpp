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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(head!=nullptr) {
            if (head->val == val) {
                if(head->next==nullptr){temp->next=nullptr;}
                head = head->next;
            } else {
                temp->next = head;
                temp=temp->next;
                head=head->next;
            }
        }
        return dummy->next;
    }
};