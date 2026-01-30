/**
 * @brief Dynamic programming for minimum paint cost
 * @intuition Each house color depends on min of other colors for previous house
 * @approach Track costs for each color, update based on previous minimum
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static auto minCost(const std::vector<std::vector<int>>& costs) -> int {
    int red = 0;
    int green = 0;
    int blue = 0;
    
    for (const auto& cost : costs) {
      const int prevRed = red;
      const int prevGreen = green;
      const int prevBlue = blue;
      red = std::min(prevGreen, prevBlue) + cost[0];
      green = std::min(prevRed, prevBlue) + cost[1];
      blue = std::min(prevRed, prevGreen) + cost[2];
    }
    return std::min({red, green, blue});
  }
};
