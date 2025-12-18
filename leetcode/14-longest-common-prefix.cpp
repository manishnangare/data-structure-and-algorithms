class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for(int i =0; i<strs[0].size();i++)
        {
            char x = strs[0][i];

            for(int j =0; j<strs.size();j++)
            {
                if(i >= strs[j].size())
                    return ans;
                else if( strs[j][i] != x)
                    return ans;
              
            }
            ans.push_back(x);
        }

        return ans;

    }
};