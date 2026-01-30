/**
 * @brief GCD of card frequencies for valid grouping
 * @intuition Valid partition exists if GCD of all counts >= 2
 * @approach Count each card, compute GCD of all frequencies
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool hasGroupsSizeX(const vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (const int x : deck) {
            ++cnt[x];
        }
        int g = cnt[deck[0]];
        for (const auto& [_, x] : cnt) {
            g = gcd(g, x);
        }
        return g >= 2;
    }
};
