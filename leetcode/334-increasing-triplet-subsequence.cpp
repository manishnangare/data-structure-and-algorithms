class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(nums.size() < 3)
            return false;
        else
        {
            int a = INT_MAX, b = INT_MAX;

            for(int i : nums)
            {
                if( i <= a )
                    a = i;
                else if (i <= b)
                    b = i;
                else
                    return true;
            }
            return false;
        }
    }
};