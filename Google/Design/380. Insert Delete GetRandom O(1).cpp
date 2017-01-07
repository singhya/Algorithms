class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int,int>m;
    vector<int> list;
    RandomizedSet() {
        list = vector<int>();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.empty() || m.find(val)==m.end()) {
            list.push_back(val);
            m[val] = list.size()-1;
            return true;
        }
        else
            return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.empty() || m.find(val)==m.end())
            return false;
        else {
            int index = m[val];
            list[index] = list[list.size()-1];
            m[list[list.size()-1]] = index;
            if(list.size()>0) list.pop_back();
            m.erase(val);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand()%list.size();
        return list[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
