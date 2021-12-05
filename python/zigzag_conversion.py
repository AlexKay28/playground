"""
6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
"""

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        
        if len(s) < 2 or numRows == 1:
            return s
        
        mask = ["" for _ in range(numRows)]
        
        down = True
        array_idx = 0
        for w in s:
            mask[array_idx] += w
            if down:
                array_idx += 1
                down = False if array_idx == numRows - 1 else True
            else:
                array_idx -= 1
                down = True if array_idx == 0 else False
        
        return "".join(mask)
