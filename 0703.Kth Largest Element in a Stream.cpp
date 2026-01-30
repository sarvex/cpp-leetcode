/**
 * @brief Min-heap to maintain k largest elements
 * @intuition Keep only k largest elements; smallest of these is kth largest
 * @approach Use min-heap of size k, evict smallest when exceeding k elements
 * @complexity Time: O(n log k) for init, O(log k) per add, Space: O(k)
 */
class KthLargest final {
public:
    KthLargest(const int k, const std::vector<int>& nums) : k_(k) {
        for (const int x : nums) {
            add(x);
        }
    }

    [[nodiscard]] int add(const int val) {
        minHeap_.push(val);
        if (minHeap_.size() > k_) {
            minHeap_.pop();
        }
        return minHeap_.top();
    }

private:
    size_t k_;
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap_;
};
