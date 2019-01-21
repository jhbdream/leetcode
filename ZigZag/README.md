The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```


Example :
```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

我的思路
1、计算每一个 N 需要几个字母 根据规律 设 ROW = n 则构成一个N 需要 2n+n-2=3n-2 个字母