#include <algorithm>
#include <array>
#include <string_view>

class Solution {
public:
  /**
   * Finds longest substring without character repetition using sliding window.
   * @intuition: Each character's last position determines where new windows can start.
   * @approach: Track last positions in fixed array, adjust window on duplicates.
   * @complexity: O(n) time, O(1) space (128 ASCII chars).
   */
  [[nodiscard]] static constexpr int
  lengthOfLongestSubstring(std::string_view input) noexcept {
    constexpr std::array<int, 128> emptyPositions{};
    std::array<int, 128> lastPositions = emptyPositions;
    int longestLength = 0;
    int currentWindowStart = 0;

    for (int currentPos = 0; currentPos < static_cast<int>(input.size()); ++currentPos) {
      const auto currentChar = static_cast<unsigned char>(input[currentPos]);
      const bool isFirstOccurrence = !lastPositions[currentChar];
      currentWindowStart = std::max(currentWindowStart, isFirstOccurrence ? 0 : lastPositions[currentChar]);

      const int currentWindowLength = currentPos - currentWindowStart + 1;
      longestLength = std::max(longestLength, currentWindowLength);
      lastPositions[currentChar] = currentPos + 1;
    }
    return longestLength;
  }
};
