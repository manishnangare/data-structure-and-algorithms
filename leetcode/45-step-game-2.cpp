class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> step(nums.size(),0);

        for(int i =0; i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size() && j<= i+nums[i];j++)
            {
                if(step[j] == 0)
                {
                    step[j] = step[i]+1;
                }
                else
                {
                    step[j] = min(step[i] + 1,step[j]);
                }
            }
        }

        return step[nums.size()-1];
    }
};