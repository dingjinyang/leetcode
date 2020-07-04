/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (66.01%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 102.7K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i, j;
    int **arr = malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int *));
    for (i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        arr[i] = malloc((i + 1) * sizeof(int *));
        for (j = 0; j <= i; j++) {
            if (i == j || j == 0) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr;
}


// @lc code=end

