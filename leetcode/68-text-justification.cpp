class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> out ;
        string a = "";

        while( words.size() > 0)
        {
            int wordLen = words.front().size();

            if(a.size() + wordLen  == maxWidth)
            {
                a.append(words.front());
                words.erase(words.begin());
                out.push_back(a);
                a = "";
            }
            else if(a.size() + wordLen > maxWidth)
            {
                a.pop_back();
                int diff = maxWidth - a.size();

                
                vector<int> spaceIndex ;
                
                for(int i =0; i< a.size();i++)
                {
                    if(a.at(i) == ' ')
                        spaceIndex.push_back(i);
                }
                if(spaceIndex.size() == 0)
                {
                    while(diff > 0)
                    {
                        a.push_back(' ');
                        diff--;
                    }
                }
                else 
                {
                    while( diff > 0)
                    {
                        for( int i =0; i < spaceIndex.size() && diff>0;i++)
                        {
                            a.insert( spaceIndex[i], " ");
                            diff--;
                            for(int j = i+1;j<spaceIndex.size();j++)
                            {
                                spaceIndex[j]++;
                            }
                        }
                    }
                }

                out.push_back(a);
                a = "";
            }
            else
            {
                a.append(words.front());
                a.push_back(' ');
                words.erase(words.begin());
            }
        }

        if(a.size() == 0)
            return out;

        int diff = maxWidth - a.size();
        while(diff > 0)
        {
            a.push_back(' ');
            diff--;
        }

        out.push_back(a);
        return out;
    }
};