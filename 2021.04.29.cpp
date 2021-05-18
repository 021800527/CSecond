/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 翻转链表

        // 每条都给一个空白的头结点，防止溢出
        ListNode* ll1 = new ListNode(0);
        ListNode* ll2 = new ListNode(0);
        ll1 -> next = l1;
        ll2 -> next = l2;
        add(ll1,ll2);

    }
    ListNode* add(ListNode* l1,ListNode* l2){
        if ()
    }
};