class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size()-1;
        int mid;

        while( l<=r)
        {
            mid = (l+r)/2;

            if(nums[mid] == target)
            {
                break;
            }
            else if(nums[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        if( l>r)
        {
            return {-1,-1};
        }
        else
        {
            cout<<mid;
            int a = mid;
            while(a > -1 && nums[a] == target)
            {
                a--;
            }
            int b = mid;
            while(b < nums.size() && nums[b] == target)
            {
                b++;
            }

            return {++a,--b};
        }
    }
};