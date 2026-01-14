class Solution {
public:
    string minWindow(string s, string t) {

        map<char,int> m;
        int nc = 0;

        for(char c : t)
        {
            if( m[c] == 0)
            {
                nc++;
            }
            m[c]++;
        }

        int i=0,j=0;
        map<char,int> n;
        int cnt = 0;
        string ans = "";

        while( i<=j && j < s.size())
        {
            //expanding phase 

            while(j<s.size() && cnt < nc)
            {
                n[s.at(j)]++;

                if(n[s.at(j)] == m[s.at(j)])
                    cnt++;
                j++;
            }

            if(j == s.size() && cnt != nc)
                break;
            
            j--;

            //contracting phase
            while(cnt == nc)
            {
                if(m[s.at(i)] != 0)
                {
                    n[s.at(i)]--;
                    if(n[s.at(i)] < m[s.at(i)])
                    {   
                        --cnt;
                        break;
                    }
                }
                i++;
            }

            if(ans == "" || j-i+1 < ans.size())
                ans = s.substr(i,j-i+1);

            i++;
            j++;

        }
        return ans;
    }
};