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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while (headA == nullptr || headB == nullptr)
            return nullptr;
        while (node1 != node2){
            if (node1 == nullptr)
                node1 = headB;
            else
                node1 = node1 -> next;
            if (node2 == nullptr)
                node2 = headA;
            else
                node2 = node2 -> next;
        }
        return node1;
    }
};