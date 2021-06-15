/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    void reorderList(ListNode* head) {
        if (head== nullptr)
            return;
        vector<ListNode *>ves;
        ListNode *node = head;
        while (node!= nullptr)
        {
            ves.push_back(node);
            node  = node ->next;
        }
        int i = 0;
        int j = ves.size()-1;
        while (i < j){
            ves[i]->next = ves[j];
            i++;
            if (i==j)
                break;
            ves[j]->next = ves[i];
            j--;
        }
    }
};