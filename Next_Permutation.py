class Solution:
    def nextPermutation(self, num):
        k = -1
        for i in range(0, len(num)-1):
            if num[i] < num[i+1]:
                k = i
        if k == -1:
            num.reverse()
            return num
        else:
            for i in range(k+1, len(num)):
                if num[i] > num[k]:
                    l = i
            num[l], num[k] = num[k], num[l]
            num[k+1:len(num):1] = num[len(num)-1:k:-1]
            return num
            
