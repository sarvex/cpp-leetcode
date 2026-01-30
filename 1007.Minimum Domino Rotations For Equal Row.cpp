/**
 * @brief Greedy counting for uniform row creation
 * @intuition Only first element values can potentially fill entire row
 * @approach Count occurrences of candidate values, compute minimum rotations
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minDominoRotations(
        const std::vector<int>& tops,
        const std::vector<int>& bottoms) {
        
        const int n = static_cast<int>(tops.size());
        
        auto f = [&](const int x) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return n + 1;
                }
                cnt1 += tops[i] == x;
                cnt2 += bottoms[i] == x;
            }
            return n - std::max(cnt1, cnt2);
        };
        
        const int ans = std::min(f(tops[0]), f(bottoms[0]));
        return ans > n ? -1 : ans;
    }
};
