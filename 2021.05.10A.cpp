#include<iostream>
using namespace std;

typedef struct Node{
    Node *left;
    Node *right;
    int val;
}Node;

class Solution {
public:
    Node* head = nullptr;// 设置返回头结点
    Node* pre = nullptr;// 设置前置结点
    Node* cur = nullptr;// 设置当前结点
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        DFS(root);
        head -> left = cur;
        cur -> right = head;
        return head;
    }
    void DFS(Node *root){
        if (root != nullptr &&root->left!=nullptr) {
            treeToDoublyList(root->left);
        }
        if (head == nullptr)
        {
            head = root;
            cur = root;
        }
        else
        {
            pre = cur;
            cur = root;
            pre -> right = cur;
            cur -> left = pre;
        }
        if (cur -> right == nullptr)
        {
            head -> left = cur;
        }
        if (root != nullptr && root -> right !=nullptr)
        {
            treeToDoublyList(root->right);
        }
    }
};