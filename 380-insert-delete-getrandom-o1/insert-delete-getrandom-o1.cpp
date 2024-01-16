class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)!=0) return false;
        mp[val]++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0) return false;
        mp.erase(val);
        v.erase(std::remove(v.begin(), v.end(), val), v.end());
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */