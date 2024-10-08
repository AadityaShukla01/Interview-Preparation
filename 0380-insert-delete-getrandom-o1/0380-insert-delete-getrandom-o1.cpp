class RandomizedSet {
public:
    unordered_map<int,int>map; //since we need to do every opeartion in o(1) time
    vector<int>nums; // since we need random no & to record insertion & deletions
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end())
            return false;
         nums.push_back(val);
        map[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        int last=nums[nums.size()-1];
        map[last]=map[val];
        nums[map[val]]=last;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        if(map.size()==0)
            return -1;
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */