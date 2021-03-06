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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast -> next;
        }
        while (fast!= nullptr)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};