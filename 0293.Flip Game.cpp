/**
 * @brief Generate all possible next moves in flip game
 * @intuition Find consecutive "++" and replace with "--"
 * @approach Scan string for "++" patterns, generate each flip
 * @complexity Time: O(n), Space: O(n) for output
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        const int n = static_cast<int>(s.size());
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                ans.emplace_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return ans;
    }
};
