/**
 * @brief Find rectangle dimensions with area and minimal length difference
 * @intuition Start from sqrt(area), find first divisor going down
 * @approach Width is largest factor <= sqrt(area), length = area / width
 * @complexity Time: O(sqrt(area)), Space: O(1)
 */
#include <cmath>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto constructRectangle(int area) const -> std::vector<int> {
        int w = static_cast<int>(std::sqrt(area));

        while (area % w != 0) {
            --w;
        }

        return {area / w, w};
    }
};
