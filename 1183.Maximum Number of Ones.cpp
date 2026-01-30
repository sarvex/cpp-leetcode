/**
 * @brief Maximize 1s in matrix with periodic sub-rectangle constraint
 * @intuition Due to periodicity, each position in the sub-rectangle appears multiple times in full matrix
 * @approach Count how many times each position in sideLength x sideLength pattern appears in full matrix.
 *           Greedily place 1s at positions with highest occurrence counts.
 * @complexity Time: O(width * height / sideLength^2 + sideLength^2 * log(sideLength^2)), Space: O(sideLength^2)
 */
class Solution final {
public:
    [[nodiscard]] static int maximumNumberOfOnes(const int width, const int height,
                                                  const int sideLength, const int maxOnes) {
        const int x = sideLength;
        vector<int> cnt(x * x);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int k = (i % x) * x + (j % x);
                ++cnt[k];
            }
        }
        ranges::sort(cnt, greater<int>());
        int ans = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
};
