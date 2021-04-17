/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode *pre = new ListNode();
        ListNode *cur = new ListNode();
        vector<int>res;
        pre = head;
        cur = NULL;
        while (pre!=NULL){
            ListNode *t = pre -> next;
            pre -> next = cur;
            cur = pre;
            pre = t;
        }
        while (cur!=NULL) {
            res.push_back(cur->val);
            head = cur ->next;
        }
        return res;
    }
};