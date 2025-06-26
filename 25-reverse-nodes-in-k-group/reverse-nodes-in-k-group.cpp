class Solution {
public:
    int getSize(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    // Standard recursive reversal
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // Recursive group reversal logic
    ListNode* solve(ListNode* head, int k, int groupsRemaining) {
        if (groupsRemaining == 0) return head;

        ListNode* tail = head;
        for (int i = 1; i < k; i++) {
            if (tail) tail = tail->next;
        }

        if (!tail) return head; // Not enough nodes

        ListNode* nextGroup = tail->next;
        tail->next = nullptr;

        ListNode* newHead = reverse(head);
        head->next = solve(nextGroup, k, groupsRemaining - 1);
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getSize(head);
        int totalGroups = size / k;
        return solve(head, k, totalGroups);
    }
};
