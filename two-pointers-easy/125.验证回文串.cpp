/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    while (start < end) {
      while (start < s.length() && !isalnum(s[start])) start++;
      while (end > -1 && !isalnum(s[end])) end--;
      if (start > end) return true;
      if (tolower(s[start]) != tolower(s[end])) return false;
      start++, end--;
    }
    return true;
  }
};
// @lc code=end
