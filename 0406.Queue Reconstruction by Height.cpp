/**
 * @brief Reconstruct queue where [h,k] means k people in front are >= h
 * @intuition Sort by height descending, then insert by k position
 * @approach Taller people placed first won't be affected by shorter insertions
 * @complexity Time: O(n^2) Space: O(n)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto reconstructQueue(std::vector<std::vector<int>>& people) const
        -> std::vector<std::vector<int>> {
        std::sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        std::vector<std::vector<int>> ans;
        for (const auto& p : people) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans;
    }
};
