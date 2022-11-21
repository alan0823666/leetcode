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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ret;
        if(list1 != nullptr || list2 != nullptr)
            ret = new ListNode();
        else {
            ret = nullptr;
            return ret;
        }
        ListNode *ptr = ret;
        
        while(list1 != nullptr && list2 != nullptr) {
            ptr -> next = new ListNode();
            if(list1 == nullptr) {
                ptr -> val = list2 -> val;
                list2 = list2 -> next;
                ptr = ptr -> next;
            }
            else if(list2 == nullptr) {
                ptr -> val = list1 -> val;
                list1 = list1 -> next;
                ptr = ptr -> next;
            }
            else if(list2 -> val > list1 -> val) {
                ptr -> val = list1 -> val;
                list1 = list1 -> next;
                ptr = ptr -> next;
            }
            else {
                ptr -> val = list2 -> val;
                list2 = list2 -> next;
                ptr = ptr -> next;
            }
            
        }
        if(list1 == nullptr) {
            while(list2 -> next != nullptr) {
                ptr -> next =  new ListNode();
                ptr -> val = list2 -> val;
                list2 = list2 -> next;
                ptr = ptr -> next;
            }
            ptr -> val = list2 -> val;
        }
        else if(list2 == nullptr) {
            while(list1 -> next != nullptr) {
                ptr -> next =  new ListNode();
                ptr -> val = list1 -> val;
                list1 = list1 -> next;
                ptr = ptr -> next;
            }
            ptr -> val = list1 -> val;
        }
        
        
        
        return ret;
    }
};