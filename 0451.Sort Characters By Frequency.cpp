/**
 * @brief Sort characters by decreasing frequency
 * @intuition Count frequencies, sort characters by count
 * @approach Use hash map for counts, sort unique chars, build result
 * @complexity Time: O(n + k log k) where k is unique chars Space: O(k)
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto frequencySort(const std::string& s) const -> std::string {
        std::unordered_map<char, int> cnt;
        for (const char c : s) {
            ++cnt[c];
        }

        std::vector<char> cs;
        for (const auto& [c, _] : cnt) {
            cs.push_back(c);
        }

        std::sort(cs.begin(), cs.end(), [&](char a, char b) {
            return cnt[a] > cnt[b];
        });

        std::string ans;
        for (const char c : cs) {
            ans += std::string(cnt[c], c);
        }

        return ans;
    }
};
