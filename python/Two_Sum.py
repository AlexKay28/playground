class Solution:
    def twoSum(self, n: List[int], t: int) -> List[int]:
        c = {}
        for i in range(len(n)):
            if n[i] in c.keys(): 
                return [i, c[n[i]]]
            else: 
                c[t - n[i]] = i
