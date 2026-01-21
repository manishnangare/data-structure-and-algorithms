class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size() == 1)
            return {nums};

        vector<vector<int>> res;
        vector<int> temp;


        for(int i=0; i<nums.size();i++)
        {
            temp = nums;
            temp.erase(temp.begin() + i);

            vector<vector<int>> nextPermute = permute(temp);

            for(vector<int> a : nextPermute)
            {
                a.insert(a.begin(), nums[i]);
                res.push_back(a);
            }
        }

        return res;
    }
};