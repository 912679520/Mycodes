#include<iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* cur = new ListNode(0);
        cur->next = head;
        ListNode* tmp = cur;

        while (cur->next)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }

        return tmp->next;
    }
};