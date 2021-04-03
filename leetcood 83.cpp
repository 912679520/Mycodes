#include<iostream>
using namespace std;

#if 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;

        while (p && p->next)
        {
            if (p->next->val == p->val)
            {
                ListNode* q = p->next;
                p->next = p->next->next;
                delete q;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }  
};
#endif
