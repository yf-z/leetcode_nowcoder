class MyHashSet {
public:
    /** Initialize your data structure here. */
    set<int> hashSet;
    MyHashSet() {
        
    }
    
    void add(int key) {
        this->hashSet.insert(key);
    }
    
    void remove(int key) {
        auto it = this->hashSet.find(key);
        if (it != this->hashSet.end())
            this->hashSet.erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto it = this->hashSet.find(key);
        if (it != this->hashSet.end())
            return true;
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */