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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        /*
             * 定义两个快慢指针
        */
        ListNode *fast = new ListNode(0);
        ListNode *slow = new ListNode(0);
        fast = head;
        slow = head;
        for (int i = 0; i < k; ++i) {
            fast = fast -> next;
        }
        while (fast!=NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};