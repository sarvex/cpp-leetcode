/**
 * @brief Greedy patching to cover range [1, n]
 * @intuition If we can cover [1, x-1], either extend with nums[i] or patch with x
 * @approach Track covered range, patch when gap exists
 * @complexity Time: O(m + log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minPatches(const std::vector<int>& nums, const int n) {
        long long covered = 1;
        int patches = 0;
        int i = 0;
        const int m = static_cast<int>(nums.size());
        
        while (covered <= n) {
            if (i < m && nums[i] <= covered) {
                covered += nums[i++];
            } else {
                ++patches;
                covered <<= 1;
            }
        }
        return patches;
    }
};
