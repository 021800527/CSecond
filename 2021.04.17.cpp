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
    ListNode(int x) : val(x),next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
         * 定义返回指针
         */
        ListNode *res = new ListNode(0);
        ListNode *Tres = res;
        /*
         * 循环
         */
        while (l1!=NULL && l2!= NULL){
            if (l1->val <= l2 -> val){
                res -> next = l1;
                l1 = l1 ->next;
                res = res -> next;
            }
            else
            {
                res -> next = l2;
                l2 = l2 -> next;
                res = res ->next;
            }
        }
        if (l1!=NULL){
            res -> next = l1;
            l1 = l1 -> next;
        }
        if (l2!=NULL){
            res -> next =l2;
            l2 = l2 ->next ;
        }
        return Tres -> next;
    }
};