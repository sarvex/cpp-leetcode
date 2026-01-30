/**
 * @brief Hash map tracking last occurrence for nearby duplicates
 * @intuition Store last index of each value, check distance constraint
 * @approach Map values to indices, verify duplicate distance <= k
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto containsNearbyDuplicate(const std::vector<int>& nums, int k) -> bool {
        std::unordered_map<int, int> lastIndex;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (auto it = lastIndex.find(nums[i]); it != lastIndex.end() && i - it->second <= k) {
                return true;
            }
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};
