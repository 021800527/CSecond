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

typedef struct Node{
    Node *left;
    Node *right;
    int val;
}Node;

class Solution {
public:
    Node* head = nullptr;//定义返回结点
    Node* pre = nullptr;//定义前一个结点
    Node* cur = nullptr;//定义当前结点
    Node* treeToDoublyList(Node* root) {
        if (root== nullptr)
            return nullptr;
        DFS(root);
        head -> left = cur;
        cur -> right = head;
        return head;
    }
    //需要DFS
    void DFS(Node* root){
        //DFS的核心思想就是左左中右右
        if (root->left != nullptr)
            treeToDoublyList(root->left);
        // 接下来就是到最左边的时候的操作了
        // 确认返回结点是否为空，为空应该赋予初值
        if (head == nullptr)
        {
            head = root;
            cur = root;
        }
        // 如果不空就应该执行连接操作
        else
        {
            //先用pre存储之前的结点
            pre = cur;
            //修改当前指针值
            cur = root;
            //连接操作
            pre -> right = cur;
            cur -> left = pre;
        }
        //这里有一个收尾相连的操作,其实是多余操作
        if (cur->right== nullptr)
        {
            head -> left = cur;
        }
        //DFS向右
        if (root ->right != nullptr)
            treeToDoublyList(root->right);


    }
};