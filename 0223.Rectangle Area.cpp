/**
 * @brief Total area of two rectangles minus overlap
 * @intuition Sum individual areas, subtract intersection if it exists
 * @approach Calculate overlap dimensions using min/max of coordinates
 * @complexity Time: O(1), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static constexpr auto computeArea(const int ax1, const int ay1, const int ax2, const int ay2,
                                                   const int bx1, const int by1, const int bx2, const int by2) noexcept -> int {
    const int areaA = (ax2 - ax1) * (ay2 - ay1);
    const int areaB = (bx2 - bx1) * (by2 - by1);
    const int overlapWidth = std::min(ax2, bx2) - std::max(ax1, bx1);
    const int overlapHeight = std::min(ay2, by2) - std::max(ay1, by1);
    const int overlap = std::max(overlapHeight, 0) * std::max(overlapWidth, 0);
    return areaA + areaB - overlap;
  }
};
