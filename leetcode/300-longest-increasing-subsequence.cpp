class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> temp(nums.size(),1);
        int l = 1,m =1;

        for( int i = nums.size()-1;i>=0;i--)
        {
            l = 1;

            for(int j =i+1;j<nums.size();j++)
            {
                if( nums[j] > nums[i])
                {
                    l = max(temp[j] + 1 , l);
                }
            }
            temp[i] = l;

            m = max(m,l);
        }

        return m;
    }
};