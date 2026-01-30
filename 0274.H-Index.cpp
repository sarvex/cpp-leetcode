/**
 * @brief Compute H-Index using descending sort and linear scan
 * @intuition Sort citations descending; H-Index is largest h where at least h papers have >= h citations
 * @approach Sort descending, enumerate and check h-index condition
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
  [[nodiscard]] static auto hIndex(const std::vector<int>& citations) -> int {
    auto sorted = citations;
    std::ranges::sort(sorted, std::greater<>());
    
    for (std::size_t h = 0; h < sorted.size(); ++h) {
      if (sorted[h] < static_cast<int>(h) + 1) {
        return static_cast<int>(h);
      }
    }
    return static_cast<int>(sorted.size());
  }
};
