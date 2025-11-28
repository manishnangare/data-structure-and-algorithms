class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        n = nums.count(val)

        i =0

        while i in range(n):
            nums.remove(val) 
            i+=1

        