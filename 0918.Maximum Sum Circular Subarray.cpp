/**
 * @brief Maximum subarray sum in circular array
 * @intuition Max is either normal subarray or total - min subarray
 * @approach Track both max and min prefix sums; answer is max of both cases
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxSubarraySumCircular(const vector<int>& nums) {
        constexpr int inf = 1 << 30;
        int pmi = 0, pmx = -inf;
        int ans = -inf, s = 0, smi = inf;
        for (const int x : nums) {
            s += x;
            ans = max(ans, s - pmi);
            smi = min(smi, s - pmx);
            pmi = min(pmi, s);
            pmx = max(pmx, s);
        }
        return max(ans, s - smi);
    }
};
