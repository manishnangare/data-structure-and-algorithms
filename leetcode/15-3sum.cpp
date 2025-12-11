class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        sort(a.begin(),a.end());
        map<int,int> m;
        vector<vector<int>> b;
        vector<int> temp;

        map<int,map<int,map<int,int>>> n;

        for(int i =0; i<a.size();i++)
        {
                m[a[i]]++;
        }

        for(int i =0; i<a.size()-1;i++)
        {
            for(int j = i+1;j<a.size();j++)
            {
                int x = -(a[i] + a[j]);
                if( m[x] != 0 )
                {
                    if( (x == a[i] && x == a[j] && m[x] < 3) || ( x == a[i] && m[x] <2 ) || (x == a[j] && m[x] < 2))
                    {
                        continue;
                    }
                    else {
                        temp = {a[i],a[j],x};
                        sort(temp.begin(),temp.end());
                        if( n[temp[0]][temp[1]][temp[2]] == 0)
                        {
                            n[temp[0]][temp[1]][temp[2]] = 1;
                            b.push_back(temp);
                        }
                    }
                }
            }
        }
        return b;
    }
};