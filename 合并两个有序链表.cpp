


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		
		while(l1 != NULL && l2 != NULL)
		{
			if(l1->val <= l2->val)
			{
				pre->next = l1;
				l1 = l1->next;
				pre = pre->next;	
			}
			else
			{
				pre->next = l2;
				l2 = l2->next;
				pre = pre->next;	
			}	
		}
        if(l1 != NULL)
        {
            pre->next = l1;
        }
        if(l2 != NULL)
        {
            pre->next = l2;
        }
		return dummy->next;	
    }
};

