/**
 * @brief Bitmask to find max product of word lengths with no common chars
 * @intuition Use bitmask to track characters in each word
 * @approach Precompute bitmasks, check pairs with AND == 0
 * @complexity Time: O(n^2 + L) where L is total chars, Space: O(n)
 */
#include <algorithm>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int maxProduct(const std::vector<std::string>& words) const {
        const int n = static_cast<int>(words.size());
        std::vector<int> mask(n);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (const char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = std::max(ans, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
