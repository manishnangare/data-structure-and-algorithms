class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = -1;
        map<int,int> m;

        for(int i =0; i<nums.size();i++)
        {
            a = max(a,nums[i]);
            m[nums[i]]++;
        }

        for(int i =0;i<=a;i++)
        {
            if(m[i] == 0)
                return i;
        }

        return a+1;
    }
};