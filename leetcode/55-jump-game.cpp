class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1)
            return true;

        nums.insert(nums.begin(),0);

        for(int i =1; i<nums.size();i++)
        {
            nums[i] = max( nums[i-1] -1, nums[i]);
            if(nums[i] == 0 && i != nums.size()-1)
                return false;
        }

        return true;

        
    }
};