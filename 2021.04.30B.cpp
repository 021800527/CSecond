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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *oldLarge = large;
        ListNode *oldSmall = small;
        while (head!= nullptr){
            if (head->val < x) {
                small->next = head;
                small = small -> next;
            }
            else {
                large->next = head;
                large = large -> next;
            }
            head = head -> next;
        }
        // 这是为什么啊
        /*
         * 我们将 \textit{large}large 的 \textit{next}next 指针置空，这是因为当前节点复用的是原链表的节点，而其 \textit{next}next 指针可能指向一个小于 xx 的节点
         */
        large->next = nullptr;
        small ->next = oldLarge -> next;
        return oldSmall->next;
    }
};