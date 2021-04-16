#include <iostream>
using namespace std;
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
    ListNode(int x) : val(),next(NULL){}
}ListNode,*LinkList;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0);
        ListNode *res = new ListNode(0);
        pre = head;
        res = NULL;
        while (pre!=NULL){
            /*
             * 需要保存下一个元素的信息
             */
            ListNode *t = pre -> next;
            pre -> next  = res;
            res = pre;
            pre = t;
        }
        return res;
    }
};