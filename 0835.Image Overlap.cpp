/**
 * @brief Count maximum overlap after translating one image
 * @intuition For each pair of 1s, their offset determines a translation
 * @approach For every pair of 1s (one from each image), compute translation
 *           vector. Count frequency of each translation; max count is answer.
 * @complexity Time: O(n^4), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto largestOverlap(const std::vector<std::vector<int>>& img1,
                                              const std::vector<std::vector<int>>& img2) -> int {
        const int n = static_cast<int>(img1.size());
        std::map<std::pair<int, int>, int> cnt;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) {
                    for (int h = 0; h < n; ++h) {
                        for (int k = 0; k < n; ++k) {
                            if (img2[h][k]) {
                                ans = std::max(ans, ++cnt[{i - h, j - k}]);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
