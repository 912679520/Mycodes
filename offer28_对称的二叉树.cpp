��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ����
��ô���ǶԳƵġ�

���磬������?[1,2,2,3,4,4,3] �ǶԳƵġ�

? ? 1
? ?/ \
? 2 ? 2
?/ \ / \
3 ?4 4 ?3
�����������?[1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

? ? 1
? ?/ \
? 2 ? 2
? ?\ ? \
? ?3 ? ?3

?

ʾ�� 1��

���룺root = [1,2,2,3,4,4,3]
�����true
ʾ�� 2��

���룺root = [1,2,2,null,3,null,3]
�����false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

˼·������������������һ�����ӣ����������1��2��3��4��2��4��3���Զ���һ���������
�������ң����󡣱������Ҳ��1��2��3��4��2��4��3.�������������Գơ�

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return preTree(root,root);
    }

    bool preTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) return true;

        if(root1 == NULL || root2 == NULL) return false;

        if(root1->val != root2->val)
            return false;
        
        return preTree(root1->left,root2->right) && preTree(root1->right,root2->left);
    }
};
