/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
#include <iostream>
using namespace std;
typedef struct Node{
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* head = NULL;// 设置返回头结点
    Node* pre = NULL;// 设置前置结点
    Node* cur = NULL;// 设置当前结点
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)
            return NULL;
        DFS(root);
        cout<<cur->val<<endl;
        return head;
    }
    void DFS(Node *root){
        if (root != NULL &&root->left!=NULL) {
            treeToDoublyList(root->left);
        }
        if (head == NULL)
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
        if (cur -> right == NULL)
        {
            head -> left = cur;
        }
        if (root != NULL && root -> right !=NULL)
        {
            treeToDoublyList(root->right);
        }
    }
};
int main(){
    Node* root4 = new Node(4);
    Node* root2 = new Node(2);
    Node* root1 = new Node(1);
    Node* root3 = new Node(3);
    Node* root5 = new Node(5);
    root4 -> left = root2;
    root4 -> right = root5;
    root5 -> left = NULL;
    root5 -> right =NULL;
    root2 -> left = root1;
    root1 -> left = NULL;
    root1 -> right =NULL;
    root2 -> right = root3;
    root3 -> left = NULL;
    root3 -> right =NULL;

    Solution solution;
    Node* res = solution.treeToDoublyList(root4);
    return 0;
}