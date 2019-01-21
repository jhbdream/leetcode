# 5. Longest Palindromic Substring
**1、最长回文子串题目 给出一个字符串s 找出最长回文子串**
**2、s的长度最大是1000**

Example :
```
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```
解题方法：
回文串是一个对称的字符串

遍历整个字符串 调用求回文长度的函数 找出最长的回文
记录该回文起始结束位置

注意 回文长度为奇数和偶数的处理