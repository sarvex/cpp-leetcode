/**
 * @brief Find median of each sliding window of size k
 * @intuition Use two heaps with lazy deletion to maintain sorted window
 * @approach Max heap for smaller half, min heap for larger half, rebalance on updates
 * @complexity Time: O(n log k), Space: O(n)
 */
#include <queue>
#include <unordered_map>
#include <vector>

class MedianFinder final {
public:
    explicit MedianFinder(int k) : k_(k) {}

    auto addNum(int num) -> void {
        if (small_.empty() || num <= small_.top()) {
            small_.push(num);
            ++smallSize_;
        } else {
            large_.push(num);
            ++largeSize_;
        }
        rebalance();
    }

    auto removeNum(int num) -> void {
        ++delayed_[num];
        if (num <= small_.top()) {
            --smallSize_;
            if (num == small_.top()) {
                prune(small_);
            }
        } else {
            --largeSize_;
            if (num == large_.top()) {
                prune(large_);
            }
        }
        rebalance();
    }

    [[nodiscard]] auto findMedian() const -> double {
        if (k_ & 1) {
            return small_.top();
        }
        return (static_cast<double>(small_.top()) + large_.top()) / 2.0;
    }

private:
    std::priority_queue<int> small_;
    std::priority_queue<int, std::vector<int>, std::greater<>> large_;
    std::unordered_map<int, int> delayed_;
    int smallSize_ = 0;
    int largeSize_ = 0;
    int k_;

    template <typename T>
    auto prune(T& pq) -> void {
        while (!pq.empty() && delayed_[pq.top()] > 0) {
            if (--delayed_[pq.top()] == 0) {
                delayed_.erase(pq.top());
            }
            pq.pop();
        }
    }

    auto rebalance() -> void {
        if (smallSize_ > largeSize_ + 1) {
            large_.push(small_.top());
            small_.pop();
            --smallSize_;
            ++largeSize_;
            prune(small_);
        } else if (smallSize_ < largeSize_) {
            small_.push(large_.top());
            large_.pop();
            ++smallSize_;
            --largeSize_;
            prune(large_);
        }
    }
};

class Solution final {
public:
    [[nodiscard]] auto medianSlidingWindow(std::vector<int>& nums, int k) const
        -> std::vector<double> {
        MedianFinder finder(k);

        for (int i = 0; i < k; ++i) {
            finder.addNum(nums[i]);
        }

        std::vector<double> ans = {finder.findMedian()};

        for (std::size_t i = k; i < nums.size(); ++i) {
            finder.addNum(nums[i]);
            finder.removeNum(nums[i - k]);
            ans.push_back(finder.findMedian());
        }

        return ans;
    }
};
