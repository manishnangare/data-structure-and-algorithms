class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        i = j = 0;

        while(i < t.size() && j < s.size())
        {
            if(t.at(i) == s.at(j))
                j++;
            
            i++;
        }

        if(j == s.size())
            return true;
        else 
            return false;
    }
};