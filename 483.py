from math import *
class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        n = int(n)
        for m in range(n.bit_length(),2,-1):
            k = int(n**(1/floor(m-1)))
            if(k**m-1)//(k-1) == n:
                return str(k)
     
        return str(n-1)