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
    int sum = 0;
    int d = 1;
    int getDecimalValue(ListNode* head) {
        if (head == nullptr)
            return 0;
        add(head);
        return sum;
    }
    void add(ListNode* head){
        if (head -> next!= nullptr)
            getDecimalValue(head -> next);
        //现在来到了最右边的结点
        //开始累加
        sum = sum + d*head->val;
        d = d * 2;
    }
};