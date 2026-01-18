class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int i =0, j = nums.size()-1, count = 0,sum;

        while(i < j)
        {
            sum = nums[i] + nums[j];
            if( sum == k)
            {
                count++;
                i++;
                j--;
            }
            else if(sum < k)
                i++;
            else 
                j--;
        }
        return count;
    }
};