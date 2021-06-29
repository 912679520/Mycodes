��ʵ�� copyRandomList ����������һ�����������ڸ��������У�
ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬
����һ�� random ָ��ָ�������е�����ڵ���� null��

ʾ�� 1��

���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
�����[[7,null],[13,0],[11,4],[10,2],[1,0]]
ʾ�� 2��

���룺head = [[1,1],[2,1]]
�����[[1,1],[2,1]]
ʾ�� 3��

���룺head = [[3,null],[3,0],[3,null]]
�����[[3,null],[3,0],[3,null]]
ʾ�� 4��

���룺head = []
�����[]
���ͣ�����������Ϊ�գ���ָ�룩����˷��� null��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

/*
˼�룺����һ����ϣ���ù�ϣ��洢�� 
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*,Node*> map;

        for(Node* cur = head; cur!=NULL; cur = cur->next)
        {
            map[cur] = new Node(cur->val);
        }

        for(Node* cur = head; cur != NULL; cur = cur->next)
        {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
        }
        return map[head];
    }
};
