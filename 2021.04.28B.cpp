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
#include <iostream>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    // 切链操作
    ListNode* sortList(ListNode* head) {
        // 空链表或者只有一个元素，直接返回
        if (head == nullptr || head -> next == nullptr)
            return head;
        // 设置快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        // 寻找中间结点
        while (fast -> next!= nullptr && fast -> next -> next!= nullptr)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        // 切链
        fast = slow -> next ;
        slow -> next = nullptr;
        // 有序和并两条有序链表
        return merge(sortList(head), sortList(fast));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        // 定义新的替身指针
        ListNode* ll1 = new ListNode(0);
        ll1 -> next = l1;
        // 保存头指针
        ListNode* res = ll1;
        while (l1 != nullptr && l2 != nullptr ){
            if (l1 -> val <= l2->val){
                ll1 -> next = l1;
                l1 = l1 -> next;
                ll1 = ll1 -> next;
            } else{
                ll1 -> next = l2;
                l2 = l2 ->next;
                ll1 = ll1 -> next;
            }
        }
        if (l1!= nullptr){
            ll1 -> next = l1;
        }
        else if (l2!= nullptr){
            ll1 -> next = l2;
        }
        return res -> next;
    }
};