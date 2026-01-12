class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int ws = words[0].size(), nw = words.size();
        int b =0;
        int f = b + ws*nw;
        map<string,int> m;
        vector<int> ans;
        vector<string> uw;

        if(nw == 5000)
        {
            for(int i=0;i<=s.size()-nw;i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        for(int i=0;i< words.size();i++)
        {
            if(m[words[i]] == 0)
            {
                uw.push_back(words[i]);
            }
            m[words[i]]++;
            
        }

        while( f<=s.size())
        {
            f = b + ws*nw;
            map<string,int> n;
            bool isValid = true;

            for(int i=b;i<f;i= i+ws)
            {
                //cout<<s.substr(i,ws)<<" ";
                if( m[s.substr(i,ws)] != 0 )
                {
                    n[s.substr(i,ws)]++;
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            //cout<<endl;
            if(isValid)
            {
                for(int i=0;i<uw.size();i++)
                {
                    if(n[uw[i]] != m[uw[i]])
                    {
                        isValid = false;
                        break;
                    }
                }
                if(isValid)
                {
                    ans.push_back(b);
                }
            }
            b+=1;
            f+=1;

        }

        return ans;

    }
};