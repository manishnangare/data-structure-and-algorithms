class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        count = 1
        curr = nums[0]
        prev = curr

        for i in range(1, len(nums)):
            prev = curr
            curr = nums[i]

            if prev != curr :
                nums[count] = curr
                count+=1
        
        return count

        

        