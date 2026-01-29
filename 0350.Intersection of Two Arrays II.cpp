/**
 * @brief Find intersection of two arrays (with duplicates)
 * @intuition Use hash map to count elements in first array
 * @approach Decrement count for each match found in second array
 * @complexity Time: O(m + n), Space: O(min(m, n))
 */
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<int> intersect(const std::vector<int>& nums1, 
                                              const std::vector<int>& nums2) const {
        std::unordered_map<int, int> cnt;
        for (const int x : nums1) {
            ++cnt[x];
        }
        
        std::vector<int> ans;
        for (const int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
