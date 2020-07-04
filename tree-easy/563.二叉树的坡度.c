/*
 * @lc app=leetcode.cn id=563 lang=c
 *
 * [563] 二叉树的坡度
 *
 * https://leetcode-cn.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (53.78%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 18.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，计算整个树的坡度。
 * 
 * 一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。
 * 
 * 整个树的坡度就是其所有节点的坡度之和。
 * 
 * 示例:
 * 
 * 
 * 输入: 
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * 输出: 1
 * 解释: 
 * 结点的坡度 2 : 0
 * 结点的坡度 3 : 0
 * 结点的坡度 1 : |2-3| = 1
 * 树的坡度 : 0 + 0 + 1 = 1
 * 
 * 
 * 注意:
 * 
 * 
 * 任何子树的结点的和不会超过32位整数的范围。
 * 坡度的值不会超过32位整数的范围。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * 后序递归遍历二叉树，每个结点的坡度等于左子树的结点之和和右子树结点之和的差的绝对值
 * 通过遍历累加所有结点的坡度
 **/
int traverse(struct TreeNode *root, int *tilt)
{
    int l, r;
    if (root)
    {
        l = traverse(root->left, tilt);
        r = traverse(root->right, tilt);
        *tilt += abs(l - r);
        return l + r + root->val;
    }
    return 0;
}

int findTilt(struct TreeNode *root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}


// @lc code=end

