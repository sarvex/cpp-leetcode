/**
 * @brief Meet-in-the-middle approach for split array with same average
 * @intuition Transform problem: if both parts have same average, their sum*n equals total*size
 * @approach Normalize values by subtracting average. Split array in half and enumerate all
 *           subset sums for first half. For second half, check if complement exists.
 *           A valid split exists if we can find subsets summing to 0.
 * @complexity Time: O(2^(n/2)), Space: O(2^(n/2))
 */
class Solution final {
public:
    [[nodiscard]] static auto splitArraySameAverage(std::vector<int>& nums) -> bool {
        const int n = static_cast<int>(nums.size());
        if (n == 1) return false;
        
        const int s = std::accumulate(nums.begin(), nums.end(), 0);
        for (int& v : nums) {
            v = v * n - s;
        }
        
        const int m = n >> 1;
        std::unordered_set<int> vis;
        
        for (int i = 1; i < (1 << m); ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j) & 1) {
                    t += nums[j];
                }
            }
            if (t == 0) return true;
            vis.insert(t);
        }
        
        for (int i = 1; i < (1 << (n - m)); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j) {
                if ((i >> j) & 1) {
                    t += nums[m + j];
                }
            }
            if (t == 0 || (i != (1 << (n - m)) - 1 && vis.count(-t))) {
                return true;
            }
        }
        return false;
    }
};
