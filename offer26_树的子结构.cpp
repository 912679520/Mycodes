 
 /*
 	�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)

B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

����:
�������� A:

      3
   /    \
  4      5
 / \
1  2
�������� B��

? ?4?
? /
?1
���� true����Ϊ B �� A ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

ʾ�� 1��

���룺A = [1,2,3], B = [3,1]
�����false
ʾ�� 2��

���룺A = [3,4,5,1,2], B = [4,1]
�����true

 */
 
 
 ///////////////////////////////////////////////////////
 /*
 	˼·�� ��������������ȿ��������ĸ��Ƿ���ȡ�
	 1����Ҫ����ȣ��ͽ��űȽ�������SubTreeEqual������ �ݹ���ã����������������ȣ�
	 ���������������ȣ�Ҫ��һֱ��BΪ���ˣ�˵���Ƚϵ���B�������һֱ����ȵģ�
	 AҪ�ǵ��ڿգ�˵��A������û���ˣ������������� 
	 2����ʼ�ĸ�Ҫ�ǲ��ȣ���ô���������������A�����ҵ���B���ڵ���ȵ� 
 */
 
 
 /*
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;
        if(A == NULL || B == NULL) return result;

        if(A->val == B->val)
            result = SubTreeEqual(A,B);
        if(!result)
            result = isSubStructure(A->left, B);
        if(!result)
            result = isSubStructure(A->right,B);
        
        return result;
    }

    bool SubTreeEqual(TreeNode* A, TreeNode* B)
    {
        if(B == NULL) return true;
        if(A == NULL) return false;

        if(A->val != B->val) return false;

        return SubTreeEqual(A->left,B->left) && SubTreeEqual(A->right,B->right);
    }
};
