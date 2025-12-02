class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        itemCount = {}

        for i in nums:
            itemCount[i] = itemCount.get(i,0) + 1

            if( itemCount[i] > len(nums)/2):
                return i
        
        return 0