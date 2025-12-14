class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ltr = nums; // Left to right prefix multiplication.
        //vector nums will be the righ to left prefix multiplication.
        

        //assigning ltr
        for(int i =1; i<nums.size();i++)
        {
            ltr[i] *= ltr[i-1];
        }
        
        //assigning nums 
        for(int i = nums.size()-2; i>=0;i--)
        {
            nums[i] *= nums[i+1];
        }

        //storing values of first and last element
        int b = ltr[nums.size()-2];
        int a = nums[1];

        //calculating the multiplication
        for(int i =1;i<nums.size()-1;i++)
        {
            nums[i] = ltr[i-1] * nums[i+1];
        }

        //assigning the first and last element
        nums[0] = a;
        nums[nums.size()-1] = b;

        return nums;
    }
};