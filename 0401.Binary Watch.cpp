/**
 * @brief Find all possible times with given number of LEDs turned on
 * @intuition Binary watch has 4 hour LEDs and 6 minute LEDs, count set bits
 * @approach Iterate all valid hour/minute combinations, check total bit count
 * @complexity Time: O(1) - 12*60 constant iterations Space: O(1)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto readBinaryWatch(int turnedOn) const -> std::vector<std::string> {
        std::vector<std::string> ans;

        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    ans.push_back(std::to_string(i) + ":" + (j < 10 ? "0" : "") + std::to_string(j));
                }
            }
        }

        return ans;
    }
};
