/**
 * @brief Count friend requests based on age rules using frequency counting
 * @intuition Age constraints are bounded (1-120), allowing O(1) space per age
 * @approach Count frequency of each age. For each pair of ages, check if friend
 *           request is valid based on rules. Multiply counts for total requests.
 * @complexity Time: O(n + 120^2) = O(n), Space: O(120) = O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto numFriendRequests(const std::vector<int>& ages) -> int {
        constexpr int m = 121;
        std::vector<int> cnt(m);
        
        for (const int x : ages) {
            ++cnt[x];
        }
        
        int ans = 0;
        for (int ax = 1; ax < m; ++ax) {
            for (int ay = 1; ay < m; ++ay) {
                if (!(ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100))) {
                    ans += cnt[ax] * (cnt[ay] - (ax == ay ? 1 : 0));
                }
            }
        }
        return ans;
    }
};
