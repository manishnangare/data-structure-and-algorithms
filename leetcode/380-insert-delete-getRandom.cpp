class RandomizedSet {
public:
    vector<int> set ;
    map<int,int> m;
    

    RandomizedSet() {
        

    }
    
    bool insert(int val) {
        if(m[val] == 0)
        {
            set.push_back(val);
            m[val]++;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool remove(int val) {
        if( m[val] != 0)
        {
            for( int i =0; i<set.size();i++)
            {
                if( set[i] == val)
                {
                    set.erase(set.begin() + i);
                    m[val]--;
                    return true;
                }
            }
            return true;   
        }
        else
        {
            return false;
        }
        
    }
    
    int getRandom() {
        return set[rand() % set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */