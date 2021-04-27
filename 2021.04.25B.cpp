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
#include <unordered_set>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> num(G.begin(),G.end());
        int res = 0;
        while (head!= nullptr){
            if (!num.count(head->val)){
                head  = head -> next;
                continue;
            }
            res ++;
            while (head != nullptr && num.count(head->val))
                head = head -> next;
        }
        return res;
    }
};