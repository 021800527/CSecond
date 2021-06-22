/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
#include <queue>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//感觉这就是一道层序遍历和链表的题
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        //层序遍历需要先开队列
        queue<TreeNode *>floor;
        //构造放回数组
        vector<ListNode *>res;
        if (tree == nullptr)
            return res;
        //放入头结点
        floor.push(tree);
        //层序遍历
        while (!floor.empty()){
            //当前层的大小
            int curSize = floor.size();
            //设置头结点
            ListNode* head = nullptr;
            ListNode* prev = nullptr;
            for (int i = 0; i < curSize; ++i) {
                TreeNode* currNode = floor.front();
                ListNode* newNode = new ListNode(currNode->val);
                floor.pop();
                if (head == nullptr)
                {
                    head = newNode;
                }
                else
                {
                    prev->next = newNode;
                }
                prev = newNode;

                if (currNode->left != nullptr)
                {
                    floor.push(currNode->left);
                }
                if (currNode->right != nullptr)
                {
                    floor.push(currNode->right);
                }}
            res.push_back(head);
            }
        return res;
    }
};
