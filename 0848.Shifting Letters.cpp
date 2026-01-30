/**
 * @brief Cumulative shift calculation from right to left
 * @intuition Each position shifts by sum of all shifts from that index onwards
 * @approach Process from right to left, accumulating total shift. Apply
 *           cumulative shift mod 26 to each character.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto shiftingLetters(std::string s,
                                               const std::vector<int>& shifts)
        -> std::string {
        long long t = 0;
        const int n = static_cast<int>(s.size());
        
        for (int i = n - 1; i >= 0; --i) {
            t += shifts[i];
            const int j = (s[i] - 'a' + t) % 26;
            s[i] = 'a' + static_cast<char>(j);
        }
        return s;
    }
};
