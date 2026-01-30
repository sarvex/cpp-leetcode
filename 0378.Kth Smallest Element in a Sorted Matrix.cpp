/**
 * @brief Find kth smallest element in row/column sorted matrix
 * @intuition Binary search on value, count elements <= mid
 * @approach Count uses matrix properties: start bottom-left, move up/right
 * @complexity Time: O(n log(max-min)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto kthSmallest(const std::vector<std::vector<int>>& matrix, int k) -> int {
        const auto n = static_cast<int>(matrix.size());
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        auto countLessOrEqual = [&](int mid) {
            int count = 0;
            int i = n - 1;
            int j = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    count += i + 1;
                    ++j;
                } else {
                    --i;
                }
            }
            return count;
        };

        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (countLessOrEqual(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
