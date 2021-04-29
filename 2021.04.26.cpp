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
#include <vector>
#include <unordered_set>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL)
            return NULL;
        ListNode *len = head;
        int num ;
        num = 0;
        while (len!=NULL){

            num++;
            len = len ->next;
        }
        for (int i = 0; i < k%num; ++i) {
            ListNode *p = new ListNode(0);
            p -> next = head;
            ListNode *pre = new ListNode(0);
            while(p->next!=NULL){
                pre = p ;
                p = p ->next;
            }
            if(p!=head){
                p -> next  = head;
                pre -> next = NULL;
                head = p;
            }
            else
                head = p;
        }
        return head;
    }
};