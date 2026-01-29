/**
 * @brief Reconstruct digits from scrambled English representation
 * @intuition Some letters uniquely identify digits (z->0, w->2, u->4, x->6, g->8)
 * @approach Count unique letters, then derive remaining digits by elimination
 * @complexity Time: O(n) Space: O(1)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto originalDigits(const std::string& s) const -> std::string {
        std::vector<int> counter(26, 0);
        for (const char c : s) {
            ++counter[c - 'a'];
        }

        std::vector<int> cnt(10, 0);
        cnt[0] = counter['z' - 'a'];
        cnt[2] = counter['w' - 'a'];
        cnt[4] = counter['u' - 'a'];
        cnt[6] = counter['x' - 'a'];
        cnt[8] = counter['g' - 'a'];

        cnt[3] = counter['h' - 'a'] - cnt[8];
        cnt[5] = counter['f' - 'a'] - cnt[4];
        cnt[7] = counter['s' - 'a'] - cnt[6];

        cnt[1] = counter['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = counter['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        std::string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += static_cast<char>(i + '0');
            }
        }

        return ans;
    }
};
