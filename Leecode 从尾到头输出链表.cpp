/*
	����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
*/ 




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){

    *returnSize = 0;
   if(head == NULL) return NULL;

   int stack[10001];
   int top = -1;
   while(head)
   {
       stack[++top] = head->val;
       head = head->next;
   }

    int* Nhead = (int *)malloc(sizeof(int)*(top + 1));
    while(top != -1)
        Nhead[(*returnSize)++] = stack[top--];

    return Nhead;

}
