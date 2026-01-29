/**
 * @brief Max heap for sliding window maximum
 * @intuition Track maximum in window using priority queue with lazy removal
 * @approach Store value and negated index, remove expired entries lazily
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <queue>
#include <utility>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto maxSlidingWindow(const std::vector<int>& nums, int k) const -> std::vector<int> {
    std::priority_queue<std::pair<int, int>> maxHeap;
    const auto n = static_cast<int>(nums.size());
    
    for (int i = 0; i < k - 1; ++i) {
      maxHeap.emplace(nums[i], -i);
    }
    
    std::vector<int> result;
    result.reserve(n - k + 1);
    
    for (int i = k - 1; i < n; ++i) {
      maxHeap.emplace(nums[i], -i);
      while (-maxHeap.top().second <= i - k) {
        maxHeap.pop();
      }
      result.push_back(maxHeap.top().first);
    }
    return result;
  }
};
