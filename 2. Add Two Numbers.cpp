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
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first_sum = l1->val + l2 -> val;
        if(first_sum == 0 && l1->next == nullptr && l2->next == nullptr)
            return new ListNode(0);
        return addTwoNumbers_solver(l1, l2, 0);
    }
    
    ListNode* addTwoNumbers_solver(ListNode* l1, ListNode* l2, int carry) {
        int l1_value = 0;
        int l2_value = 0;
        if(l1 != nullptr) 
            l1_value = (*l1).val;
        if(l2 != nullptr) 
            l2_value = (*l2).val;
        
        int sum = l1_value + l2_value + carry;
        cout << l1_value << " " <<  l2_value << endl;
       

        ListNode *l1_next = nullptr;
        ListNode *l2_next = nullptr;
        
        if(l1 != nullptr)
            l1_next = l1->next;
        if(l2 != nullptr)
            l2_next = l2->next;
        
         if(sum == 0 && l1_next == nullptr && l2_next == nullptr) {
            return nullptr;
        }
        
        int next_node_carry = 0;
        if(sum >= 10) {
            next_node_carry = 1;
            sum -= 10;
        }
        
        ListNode *ans = new ListNode(sum);
            ans -> next = addTwoNumbers_solver(l1_next, l2_next, next_node_carry);
        ListNode* ret_ptr = ans;
        return ret_ptr;
    }
};