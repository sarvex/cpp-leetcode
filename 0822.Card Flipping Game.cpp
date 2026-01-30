/**
 * @brief Find minimum good number in card flipping game
 * @intuition Cards with same front and back can never show that number as good
 * @approach Numbers appearing on both sides of same card are blocked. Find
 *           minimum number from all card faces that is not blocked.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto flipgame(const std::vector<int>& fronts,
                                        const std::vector<int>& backs) -> int {
        std::unordered_set<int> blocked;
        const int n = static_cast<int>(fronts.size());
        
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                blocked.insert(fronts[i]);
            }
        }
        
        int ans = 9999;
        for (const int v : fronts) {
            if (!blocked.count(v)) {
                ans = std::min(ans, v);
            }
        }
        for (const int v : backs) {
            if (!blocked.count(v)) {
                ans = std::min(ans, v);
            }
        }
        return ans % 9999;
    }
};
