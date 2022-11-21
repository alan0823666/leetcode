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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        int tmp = head -> val;
        head -> val = head -> next -> val;
        head -> next -> val = tmp; 
        head -> next -> next = swapPairs(head -> next -> next);
        
        return head;
    }
};