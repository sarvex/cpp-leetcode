/**
 * @brief Find intersection of two arrays (unique elements)
 * @intuition Use boolean array as set for first array, check second
 * @approach Mark elements from first array, collect matching from second
 * @complexity Time: O(m + n), Space: O(max element)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> intersection(const std::vector<int>& nums1, 
                                                        const std::vector<int>& nums2) {
        std::array<bool, 1001> seen{};
        
        for (const int x : nums1) {
            seen[x] = true;
        }
        
        std::vector<int> ans;
        for (const int x : nums2) {
            if (seen[x]) {
                ans.push_back(x);
                seen[x] = false;
            }
        }
        return ans;
    }
};
