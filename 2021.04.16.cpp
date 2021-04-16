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
    ListNode(int x) :val(x),next(NULL){}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *old = new ListNode(0);
        old -> next = head;
        ListNode *res  = old;
        while(head!=NULL){
            if(head -> val == val){
                old ->next = old -> next ->next;
            }
            head = head -> next;
            old = old -> next;
        }
        return res -> next;
    }
};