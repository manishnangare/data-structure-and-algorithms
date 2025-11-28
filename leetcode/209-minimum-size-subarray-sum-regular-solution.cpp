class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size(), gap = 1, a,b, minLength;

        // first find the cumulative sum of the array nums.
        for( int i =1; i< nums.size();i++)
        {
            nums[i]+= nums[i-1];
        }

        //Insert 0 at the begining of nums. 
        nums.insert( nums.begin(), 0);

        n++;

        if( nums[n-1] < target )
            return 0;
            
        minLength = n;
        a = 0;

        while( a < n)
        {
            b = a+1;
            while( b <n && nums[b]-nums[a] < target)
            {
                b++;
            }

            if( b == n)
            {
                break;
            }
            else
            {
                minLength = min( minLength, b-a);
                a++;
            }

        }

        return minLength;
        
    }
};