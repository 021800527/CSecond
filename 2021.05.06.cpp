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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        if (head -> next == nullptr)
            return true;
        //存储原来的头结点
        ListNode *oldHead = head;
        //通过快慢指针找到中间结点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr){
            fast = fast -> next -> next;
            slow = slow ->next;
        }
        //中间结点slow
        //对slow后的进行倒序排序
        ListNode *cur = slow;
        //断开链表
        slow = nullptr;
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
        //获得倒序后的头结点pre
        //进行逐个比对
        while (pre!=oldHead &&pre!= nullptr && oldHead!= nullptr){
            if (pre->val != oldHead -> val)
                return false;
            pre = pre -> next;
            oldHead = oldHead -> next;
        }
        return true;
    }
};