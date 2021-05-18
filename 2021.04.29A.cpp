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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersCore(l1, l2, 0);
    }
private:
    ListNode* addTwoNumbersCore(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            // 当输入的节点均为null且无需处理进位时，结束
            return nullptr;
        }
        int val = carry + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0); // 计算当前的和
        auto res = new ListNode(val % 10);
        res -> next = addTwoNumbersCore((l1 ? l1 -> next : nullptr), (l2 ? l2 -> next : nullptr), val / 10);
        return res;
    }
};
