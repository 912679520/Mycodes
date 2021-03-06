请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，
那么它是对称的。

例如，二叉树?[1,2,2,3,4,4,3] 是对称的。

? ? 1
? ?/ \
? 2 ? 2
?/ \ / \
3 ?4 4 ?3
但是下面这个?[1,2,2,null,3,null,3] 则不是镜像对称的:

? ? 1
? ?/ \
? 2 ? 2
? ?\ ? \
? ?3 ? ?3

?

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：用先序遍历，比如第一个例子，先序遍历是1，2，3，4，2，4，3，自定义一个先序遍历
先中再右，再左。遍历结果也是1，2，3，4，2，4，3.所以这个树镜像对称。

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
