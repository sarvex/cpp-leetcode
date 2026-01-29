/**
 * @brief Find longest consecutive sequence using hash set
 * @intuition Use set for O(1) lookup, expand from each number while removing visited
 * @approach For each unvisited number, extend sequence upward while marking as visited
 * @complexity Time: O(n), Space: O(n)
 */

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto longestConsecutive(vector<int>& nums) -> int {
        unordered_set<int> remaining(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cache;

        for (const int x : nums) {
            int y = x;
            while (remaining.contains(y)) {
                remaining.erase(y++);
            }
            cache[x] = (cache.contains(y) ? cache[y] : 0) + y - x;
            ans = std::max(ans, cache[x]);
        }

        return ans;
    }
};
