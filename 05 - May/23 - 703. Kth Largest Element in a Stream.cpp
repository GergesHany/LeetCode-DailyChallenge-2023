class KthLargest {
public:
    int size; // size of the heap
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    KthLargest(int k, vector<int>& nums) {
        size = k; // set the size of the heap

        // push all the elements into the heap
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]); 
            // if the size of the heap is greater than k, pop the top element
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val); // push the new element into the heap
        // if the size of the heap is greater than k, pop the top element
        if(pq.size() > size) pq.pop();
        // return the top element
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */