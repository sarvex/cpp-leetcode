/**
 * @brief Simulate tournament bracket pairing
 * @intuition In each round, strongest pairs with weakest for maximum excitement
 * @approach Start with teams 1 to n, repeatedly pair first with last until one remains
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string findContestMatch(int n) {
        vector<string> teams(n);
        
        for (int i = 0; i < n; ++i) {
            teams[i] = to_string(i + 1);
        }
        
        for (; n > 1; n >>= 1) {
            for (int i = 0; i < n >> 1; ++i) {
                teams[i] = "(" + teams[i] + "," + teams[n - i - 1] + ")";
            }
        }
        
        return teams[0];
    }
};
