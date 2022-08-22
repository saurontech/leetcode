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
    ListNode * output;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto _l1 = l1;
        auto _l2 = l2;
        int b = 0;
        auto ptr = &output;
        while(_l1 != nullptr || _l2 != nullptr || b != 0){
            auto a = ((_l1 != nullptr)?(_l1->val):0) + ((_l2 != nullptr)?(_l2->val):0) + b;
            b = 0;
            if(_l1 != nullptr){
                _l1 = _l1->next;
            }
            if(_l2 != nullptr){
                _l2 = _l2->next;
            }
            *ptr = new ListNode(a%10);
            ptr = &(*ptr)->next;
            b = a/10;
        }
        return output;
    }
};
