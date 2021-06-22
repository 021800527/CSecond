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
        // 返回的结果
        vector<ListNode*> res;
        if (tree == nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(tree);

        while (!q.empty())
        {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;
            // 只遍历当前层的大小
            int currSize = q.size();
            for (int i = 0; i < currSize; ++i)
            {
                TreeNode* currNode = q.front();
                ListNode* newNode = new ListNode(currNode->val);
                q.pop();
                // 这里需要考虑链表首结点和构建
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
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr)
                {
                    q.push(currNode->right);
                }
            }
            res.push_back(head);
        }

        return res;
    }
};
