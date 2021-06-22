 
 /*
 	输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

      3
   /    \
  4      5
 / \
1  2
给定的树 B：

? ?4?
? /
?1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true

 */
 
 
 ///////////////////////////////////////////////////////
 /*
 	思路： 根据先序遍历，先看两个树的根是否相等。
	 1、根要是相等，就接着比较子树（SubTreeEqual函数） 递归调用，左子树和左子树比，
	 右子树和右子树比，要是一直到B为空了，说明比较到了B树得最后，一直是相等的，
	 A要是等于空，说明A接下来没有了，子树不成立。 
	 2、开始的根要是不等，那么接下来就先序遍历A树，找到和B根节点相等的 
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
