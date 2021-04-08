#include<iostream>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    //Ë«Ö¸Õë×ö·¨£º
    ListNode* getKthFromEnd1(ListNode* head, int k)
    {
        ListNode* p = head;
        ListNode* q = head;

        if (head == NULL || k <= 0) return NULL;

        for (int i = 0; i < k - 1;i++)
        {
            if (p->next) p = p->next;
            else
            {
                return NULL;
            }
        }
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        return q;
    }


    int GetLinkLength(ListNode* head)
    {
        ListNode* p = head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }
        return length;
    }
    ListNode* getKthFromEnd(ListNode* head, int k)
    {
        if (head == NULL || k <= 0) return NULL;

        int length = GetLinkLength(head);
        ListNode* p = head;
        for (int i = 1; i <= length - k; i++)
        {
            p = p->next;
        }
        return p;
    }
};
