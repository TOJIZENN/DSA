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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* s = head;
        ListNode* temp = head;
        int n = 0;
        while (s != nullptr) {
            n++;
            s = s->next;
        }
        int parts = n / k;
        int rem = n % k;
        vector<ListNode*> ans;
        temp = head;

        while (temp) {
            ListNode* curr = temp;
            for (int i = 1; i < parts && temp; i++) {
                temp = temp->next;
            }
            if (rem && temp && n > k) {
                temp = temp->next;
                rem--;
            }
            if (temp) {
                ListNode* nextNode = temp->next;
                temp->next = nullptr;
                temp = nextNode;
            }
            ans.push_back(curr);
        }

        if (n < k) {
            for (int i = 0; i < k - n; i++) {
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};