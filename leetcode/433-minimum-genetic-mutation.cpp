class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        

        if(startGene == endGene)
            return 0;
        else
        {
            map<string,int> mutations;

            for(string a: bank)
            {
                mutations[a]++;
            }

            if(mutations[endGene] == 0)
                return -1;
            else
            {
                vector<string> q;
                int layer = 0;

                if(mutations[startGene] == 1)
                    mutations[startGene] = 0;

                q.push_back(startGene);

                while( q.size() > 0)
                {
                    vector<string> t;
                    layer++;

                    for(string a : q)
                    {
                        for(int i=0;i<8;i++)
                        {
                            string ts = a;
                            ts[i] = 'A';
                
                            if( a != ts && mutations[ts] != 0)
                            {
                               mutations[ts] = 0;
                               t.push_back(ts);
                            }

                            ts[i] = 'C';
                            if( a != ts && mutations[ts] != 0)
                            {
                               mutations[ts] = 0;
                               t.push_back(ts);
                               cout<<t.back()<<" "; 
                            }

                            ts[i] = 'G';
                            if( a != ts && mutations[ts] != 0)
                            {
                               mutations[ts] = 0;
                               t.push_back(ts);
                            }

                            ts[i] = 'T';
                            if( a != ts && mutations[ts] != 0)
                            {
                               mutations[ts] = 0;
                               t.push_back(ts);
                            }
                        }
                    }

                    q = t;

                    if(mutations[endGene] == 0)
                        return layer;
                }

                return -1;
            }
        }
    }
};