class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        w = 0
        for i in range(0,31):
            if (n>>i)%2 == 1:
                w = w+1
        
        return w
        