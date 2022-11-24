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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* start = head;
        ListNode* end = head;
        if(head == nullptr)
            return head;
        while(1) {
            n += 1;
            start = start -> next;
            if(start == nullptr)
                break;
            end = end -> next;

        }
        int true_k = k % n;
        int new_start_idx = n - true_k;
        if(new_start_idx == 0 || true_k == 0 || n == 1)
            return head;
        ListNode *origin = head;
        ListNode *new_start = head;
        ListNode *pre = head;
        for(int i = 0; i < new_start_idx; i++) {
            new_start = new_start -> next;
            if(i < new_start_idx - 1)
                pre = pre -> next;
        }
        pre -> next = nullptr;
        end -> next = head;
        return new_start;
    }
};