class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if( nums.size() == 1)
            return 1;
            
        int top = 1;



        for( int i = top +1; i< nums.size(); i++)
        {
            if( nums[top -1] != nums[i])
            {
                nums[top+1] = nums[i];
                top++;
            }
        }

        return ++top;
    }
};