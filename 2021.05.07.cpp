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
    ListNode* oddEvenList(ListNode* head) {
        if (head== nullptr || head->next == nullptr)
            return head;
        //存储头结点
        ListNode *oldHead = head;
        //存储第二个结点
        ListNode *oldSecondHead = head->next;
        //存储头结点
        ListNode *resoldHead = head;
        //存储第二个结点
        ListNode *resoldSecondHead = head->next;
        while (oldHead!= nullptr){
            oldHead -> next = oldHead -> next -> next;
            oldSecondHead -> next = oldSecondHead ->next;
            oldHead = oldHead -> next;
            oldSecondHead = oldSecondHead -> next;
        }
        resoldHead -> next = resoldSecondHead;
        return resoldHead;
    }
};