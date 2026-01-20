class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        int wordSize = wordList[0].size();
        vector<vector<char>> charList(wordSize,vector<char>(0));
        map<int,map<char,int>> charMap;
        map<string,int> wordMap;

        for(string a : wordList)
        {
            wordMap[a]++;
            
            for(int i=0;i<wordSize;i++)
            {
                if( charMap[i][a[i]] == 0)
                {
                    charList[i].push_back(a[i]);
                    charMap[i][a[i]]++;
                }
            }
        }

        if(wordMap[endWord] == 0)
            return 0;

        vector<string> q;
        int f = 0;
        int layer = 0;

        q.push_back(beginWord);

        wordMap[beginWord] = 0;

        while( f < q.size())
        {
            layer++;
            int b = q.size();
            while(f < b)
            {
                string a = q[f];
                for(int i=0;i<wordSize;i++)
                {
                    string x = a;
                    for(char j : charList[i])
                    {
                        x[i] = j;

                        if( x != a && wordMap[x] == 1)
                        {
                            q.push_back(x);
                            wordMap[x] = 0;
                        }
                    }
                }
                f++;
            }

            if(wordMap[endWord] == 0)
                return ++layer;
        }
        
        return 0;
    }
};