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
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // 定义返回数组
        vector<ListNode*>res;
        if (root == nullptr && k == 0 )
            return res;
        if (root == nullptr && k != 0) {
            for (int i = 0; i < k; ++i) {
                res.push_back(nullptr);
            }
            return res;
        }
        // 计算长度
        int num = 1;
        ListNode *len = root;
        while (len -> next != nullptr){
            num++;
            len = len -> next;
        }
        // 恢复头结点
        len = root;
        // 定义返回指针
        ListNode *resLen = root;
        // 判断k是否会大于表长
        if (k>=num){
            for (int i = 0; i < k; ++i) {
                resLen = len;
                res.push_back(resLen);
                if (len!= nullptr) {
                    len = len->next;
                    resLen -> next = nullptr;
                }
            }
            return res;
        }
            // 处理k小于表长的情况
        else{
            // 恢复头结点
            len = root;
            // 恢复返回指针
            resLen = root;
            // 计算余数
            int left = num % k;
            // 计算每个相等的基准值
            int every = num / k;
            for (int i = 0; i < left; ++i) {
                for (int j = 0; j < every + 1; ++j) {
                    resLen = len;
                    if (j == 0)
                        res.push_back(resLen);
                    if (len!= nullptr){
                        len = len ->next;
                    }
                    if (j == every)
                        resLen -> next = NULL;
                }
            }
            resLen = len;
            for (int i = 0; i < k-left; ++i) {
                for (int j = 0; j < every ; ++j) {
                    resLen = len;
                    if (j == 0)
                        res.push_back(resLen);
                    if (len!= nullptr){
                        len = len ->next;
                    }
                    if (j == (every-1))
                        resLen -> next = NULL;
                }
            }
            return res;
        }
    }
};