/**
 * @brief Min-heap to generate nth ugly number
 * @intuition Generate ugly numbers by multiplying known ugly numbers by 2,3,5
 * @approach Use priority queue with deduplication to find nth ugly number
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
  [[nodiscard]] static auto nthUglyNumber(int n) -> int {
    std::priority_queue<long, std::vector<long>, std::greater<>> minHeap;
    std::unordered_set<long> seen;
    
    minHeap.push(1L);
    seen.insert(1L);
    
    constexpr std::array<int, 3> factors = {2, 3, 5};
    long result = 1;
    
    while (n-- > 0) {
      result = minHeap.top();
      minHeap.pop();
      for (const int factor : factors) {
        const long next = result * factor;
        if (!seen.contains(next)) {
          seen.insert(next);
          minHeap.push(next);
        }
      }
    }
    return static_cast<int>(result);
  }
};
