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
    ListNode(int x) : val(x),next(NULL){}
};
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode* pre = head;
        ListNode* cur = head -> next;
        while (cur!=NULL){
            if (Vector(pre->val, cur->val, G))
            {
                for (int i = 0; i < G.size(); ++i) {
                    if (G[i]==pre->val){
                        G[i]=-1;
                        break;
                    }
                }
            }
            else
            {
                pre = pre ->next;
                cur = cur ->next;
            }
        }
        int num;
        num = 0;
        for (int i = 0; i < G.size(); ++i) {
            if (G[i]!=-1)
                num++;
        }
        return num;
    }
    bool Vector(int pre , int cur , vector<int> & G){
        bool flag1 = false;
        bool flag2 = false;
        for (int i = 0; i < G.size(); ++i) {
            if (pre == G[i]){
                flag1 = true;
                break;}
        }
        for (int i = 0; i < G.size(); ++i) {
            if (cur == G[i]){
                flag2 = true;
                break;;
            }
        }
        if (flag1== true && flag2 == true)
            return true;
        else
            return false;
    }
};
