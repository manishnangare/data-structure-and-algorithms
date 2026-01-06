class Trie {
public:
    vector<Trie*> letters;
    map<string,bool> m;

    Trie() {
       for(int i =0;i<26;i++)
       {
        letters.push_back(nullptr);
       }
    }
    
    void insert(string word) {
        Trie *cur = this;
        for(int i =0; i<word.size();i++)
        {
            if(cur->letters[ word.at(i) - 97] == nullptr)
            {
                Trie *t = new Trie();
                cur->letters[ word.at(i) - 97] = t;
                cur = t;
            }
            else
            {
                cur = cur->letters[ word.at(i) - 97];
            }
        }
        m[word] = true;
    }
    
    bool search(string word) {
        return m[word];
    }
    
    bool startsWith(string word) {
        Trie *cur = this;
        for(int i =0; i<word.size();i++)
        {
            if(cur->letters[ word.at(i) - 97] == nullptr)
                return false;
            else
                cur = cur->letters[ word.at(i) - 97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */