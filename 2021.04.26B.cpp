#include <iostream>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // k 为 0 或者 空表 或者 仅有一个元素的表之后直接返回头指针
        if (k == 0 || head == nullptr || head ->next == nullptr)
            return head;
        int num = 1;
        ListNode *len = head;
        // 计算链表长度
        while(len -> next != nullptr)
        {
            num ++;
            len = len -> next;
        }
        // 计算断点
        int add = num - k % num;
        // 如果add == num 直接返回
        if (add == num)
            return head;
        // 将表连接成环
        len -> next = head;
        while (add--) {
            len = len ->next;
        }
        ListNode* ret = len->next;
        len ->next = nullptr;
        return ret;
    }
};