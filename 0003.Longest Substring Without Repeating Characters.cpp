/**
 * @brief Sliding window approach for longest substring without repeating characters
 * @intuition Each character's last position determines where new windows can start
 * @approach Track last positions in fixed array, adjust window on duplicates
 * @complexity Time: O(n), Space: O(1) (128 ASCII chars)
 */

#include <algorithm>
#include <array>
#include <string>

class Solution final {
public:
  [[nodiscard]] static constexpr auto
  lengthOfLongestSubstring(const std::string& input) noexcept -> int {
    std::array<int, 128> lastPositions{};
    int longestLength = 0;
    int currentWindowStart = 0;

    for (int currentPos = 0; currentPos < static_cast<int>(input.size());
         ++currentPos) {
      const auto currentChar = static_cast<unsigned char>(input[currentPos]);
      const bool isFirstOccurrence = lastPositions[currentChar] == 0;
      currentWindowStart =
          std::max(currentWindowStart,
                   isFirstOccurrence ? 0 : lastPositions[currentChar]);

      const int currentWindowLength = currentPos - currentWindowStart + 1;
      longestLength = std::max(longestLength, currentWindowLength);
      lastPositions[currentChar] = currentPos + 1;
    }

    return longestLength;
  }
};
