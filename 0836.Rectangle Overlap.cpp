/**
 * @brief Check if two axis-aligned rectangles overlap
 * @intuition Rectangles overlap if they intersect in both x and y dimensions
 * @approach Check non-overlap conditions (one entirely left/right/above/below)
 *           and negate. Overlap exists unless separated in some dimension.
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto isRectangleOverlap(const std::vector<int>& rec1,
                                                  const std::vector<int>& rec2) -> bool {
        const int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        const int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
    }
};
