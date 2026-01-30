/**
 * @brief Greedy flower placement in flowerbed
 * @intuition Place flowers greedily when both neighbors are empty
 * @approach Check each position; if position and both neighbors are empty, plant a flower
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int m = flowerbed.size();
        for (int i = 0; i < m; ++i) {
            const int l = i == 0 ? 0 : flowerbed[i - 1];
            const int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
};
