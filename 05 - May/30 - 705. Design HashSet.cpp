class MyHashSet {
public:
    multiset < int > st; // The multiset is used to store the elements 
    MyHashSet() {
        
    }
    
    void add(int key) {
        // insert the element in the multiset
        st.insert(key);
    }
    
    void remove(int key) {
        // if the element is present in the multiset then remove it
        if (st.count(key))
          st.erase(*st.find(key));
    }
    
    bool contains(int key) {
        // check if the element is present in the multiset
        return st.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */