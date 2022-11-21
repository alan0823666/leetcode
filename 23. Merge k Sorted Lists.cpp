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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return nullptr;
        int first_element[k];
        bool list_is_empty[k];
        
        cout << 'asd';
        
        for(int i = 0; i < k; i++) {
            if(lists[i] == nullptr)
                list_is_empty[i] = true;
            else {
                list_is_empty[i] = false;
                first_element[i] = lists[i]->val;
            }
        }
        ListNode* ret;
        ListNode** ret_ptr = &ret;
        int flag_first = true;
        while(true) {
            bool all_list_is_empty = true;
            for(int i = 0; i < k; i++) {
                if(list_is_empty[i] == false) {
                    all_list_is_empty = false;
                    break;
                }
            }
            if(all_list_is_empty)
                break;
            
            int min = 100000;
            int idx = -1;
            for(int i = 0; i < k; i++) {
                if(list_is_empty[i] == false && first_element[i] < min) {
                    min = first_element[i];
                    idx = i;
                }
            }
            if(lists[idx]->next == nullptr)
                list_is_empty[idx] = true;
            else {
                lists[idx] = lists[idx]->next;
                first_element[idx] = lists[idx]->val;
            }
            (*ret_ptr) = new ListNode();
            (*ret_ptr)->val = min;
            
            ret_ptr = &(*ret_ptr)->next;
        }
        return ret;
    }
};