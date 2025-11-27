class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        i = 0
        j = 0

        while j < n:
            if i <m+j and nums1[i] <= nums2[j]:
                i+=1
            elif i <m+j and nums1[i] > nums2[j]:
                nums1.insert(i,nums2[j])
                nums1.pop()
                i+=1
                j+=1
            else:
                nums1.insert(i,nums2[j])
                nums1.pop()
                i+=1
                j+=1
