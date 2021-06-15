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
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head== nullptr)
            return nullptr;
        ListNode *cur = head;
        ListNode *pre = new ListNode(0);
        pre = nullptr;
        ListNode *centerHead = new ListNode(0);
        while (cur!= nullptr){
            // 存储原来的下一个位置
            centerHead = cur -> next;
            cur -> next = pre;
            pre = cur ;
            cur = centerHead;
        }
        return pre;
    }
};