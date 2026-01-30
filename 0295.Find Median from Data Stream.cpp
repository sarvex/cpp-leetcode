/**
 * @brief Two heaps to maintain running median
 * @intuition Keep smaller half in max-heap, larger half in min-heap
 * @approach Balance heaps so min-heap has at most one extra element
 * @complexity Time: O(log n) add, O(1) median, Space: O(n)
 */
class MedianFinder final {
public:
    MedianFinder() = default;

    void addNum(int num) {
        maxHeap_.push(num);
        minHeap_.push(maxHeap_.top());
        maxHeap_.pop();

        if (minHeap_.size() > maxHeap_.size() + 1) {
            maxHeap_.push(minHeap_.top());
            minHeap_.pop();
        }
    }

    [[nodiscard]] double findMedian() const {
        if (minHeap_.size() == maxHeap_.size()) {
            return (minHeap_.top() + maxHeap_.top()) / 2.0;
        }
        return minHeap_.top();
    }

private:
    priority_queue<int> maxHeap_;
    priority_queue<int, vector<int>, greater<>> minHeap_;
};
