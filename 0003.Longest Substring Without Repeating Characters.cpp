#include <algorithm>
#include <array>
#include <string_view>

class Solution {
public:
  /**
   * Sliding window for longest substring without repeats.
   * @intuition: Track last seen positions to efficiently skip duplicates.
   * @approach: Use a fixed-size array for ASCII, update window start on
   * repeats.
   * @complexity: O(n) time, O(1) space (ASCII charset).
   */
  [[nodiscard]] static constexpr int
  lengthOfLongestSubstring(std::string_view s) noexcept {
    std::array<int, 128> lastSeen{};
    lastSeen.fill(-1);
    int maxLen = 0, windowStart = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      const auto ch = static_cast<unsigned char>(s[i]);
      windowStart = std::max(windowStart, lastSeen[ch] + 1);
      maxLen = std::max(maxLen, i - windowStart + 1);
      lastSeen[ch] = i;
    }
    return maxLen;
  }
};
