/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
    ListNode* add(ListNode* l1,ListNode* l2,int carry){
        // 空链而且进位为0直接退出
        if (l1 == nullptr && l2 == nullptr && carry ==0)
            return nullptr;
        int sum = (l1 ? l1->val:0) + (l2?l2->val:0)  + carry;
        ListNode* res = new ListNode(sum%10);
        res -> next = add(l1?l1->next: nullptr , l2?l2->next: nullptr,sum/10);
        return res;
    }
};