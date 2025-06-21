class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();  // Remove smallest
        return minHeap.top();  // k-th largest
    }
};
