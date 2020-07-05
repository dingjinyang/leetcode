#
# @lc app=leetcode.cn id=44 lang=python3
#
# [44] 通配符匹配
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        dp[0][0] = True
        for i in range(1, n+1):
            if p[i-1] == '*':
                dp[0][i] = True
            else:
                break

        for i in range(1, m+1):
            for j in range(1, n+1):
                if p[j-1] == '?' or p[j-1] == s[i-1]:
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] | dp[i][j-1]
        return dp[-1][-1]
# @lc code=end
