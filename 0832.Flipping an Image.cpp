/**
 * @brief Flip image horizontally then invert values
 * @intuition Combine flip and invert: swap pairs and toggle if equal
 * @approach Use two pointers from ends. If values are equal, both toggle.
 *           If different, they swap but values stay same after flip+invert.
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto flipAndInvertImage(std::vector<std::vector<int>>& image)
        -> std::vector<std::vector<int>>& {
        for (auto& row : image) {
            int i = 0;
            int j = static_cast<int>(row.size()) - 1;
            
            for (; i < j; ++i, --j) {
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
            if (i == j) {
                row[i] ^= 1;
            }
        }
        return image;
    }
};
