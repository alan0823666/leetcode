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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *target, *to_the_null, *target_prev;
        target_prev = head;
        target = head;
        to_the_null = head;
        
        for(int i = 0; i < n; i++) {
            // to_the_null move forward 1
            to_the_null = to_the_null -> next;
        }
        int flag = 0;
        while(to_the_null != nullptr) {
            // target and to the null move forward 1
            to_the_null = to_the_null -> next;
            target = target -> next;
            if(flag == 1)
                target_prev = target_prev -> next;
            flag = 1;
        }

        
        if(target == head)
            return head -> next;
        target_prev->next = target->next;
        return head;
    }
};