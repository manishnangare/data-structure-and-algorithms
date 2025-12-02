class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        top = 1

        if len(nums) == 1:
            return top

        for i in range(top+1, len(nums)):
            if nums[top-1] != nums[i]:
                nums[top+1] = nums[i]
                top+=1

        top+=1
        return top;        
