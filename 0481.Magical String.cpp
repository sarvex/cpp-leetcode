/**
 * @brief Count 1s in first n characters of magical string
 * @intuition Self-describing sequence: element at i tells run length at that position
 * @approach Generate sequence up to n, alternating 1s and 2s based on run lengths
 * @complexity Time: O(n), Space: O(n)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto magicalString(int n) const -> int {
        std::vector<int> s = {1, 2, 2};

        for (std::size_t i = 2; s.size() < static_cast<std::size_t>(n); ++i) {
            const int prev = s.back();
            const int curr = 3 - prev;
            for (int j = 0; j < s[i]; ++j) {
                s.push_back(curr);
            }
        }

        return static_cast<int>(std::count(s.begin(), s.begin() + n, 1));
    }
};
