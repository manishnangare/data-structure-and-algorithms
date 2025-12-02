class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count = 1, curr = nums[0], prev;

        for( int i =1; i< nums.size(); i++)
        {
            prev = curr;
            curr = nums[i]; 

            if( prev != curr)
            {
                nums[count++] = curr;
            }
        }

        return count;
    }
};