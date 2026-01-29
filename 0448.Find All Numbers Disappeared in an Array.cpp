/**
 * @brief Find numbers 1 to n missing from array of length n
 * @intuition Mark presence using array indices, find unmarked
 * @approach Use boolean array or in-place marking to track seen numbers
 * @complexity Time: O(n) Space: O(n)
 */
#include <cstring>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findDisappearedNumbers(std::vector<int>& nums) const -> std::vector<int> {
        const int n = static_cast<int>(nums.size());
        std::vector<bool> seen(n + 1, false);

        for (const int x : nums) {
            seen[x] = true;
        }

        std::vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
