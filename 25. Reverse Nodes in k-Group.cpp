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
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool not_enough_to_k = false;
        ListNode* tmp_ptr = head;
        int value_list[k];

        for(int i = 0; i < k; i++) {
            if(tmp_ptr == nullptr) {
                not_enough_to_k = true;
                break;
            }
            value_list[i] = tmp_ptr -> val;
            tmp_ptr = tmp_ptr -> next;
        }
        if(not_enough_to_k == true)
            return head;
        ListNode* iter = head;
        for(int i = 0; i < k; i++) {
            iter -> val = value_list[k-i-1];
            iter = iter -> next;
        }
        reverseKGroup(iter, k);
        return head;
    }
    
};