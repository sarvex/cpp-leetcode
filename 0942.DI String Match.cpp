/**
 * @brief Construct permutation from DI string pattern
 * @intuition Use smallest unused for 'I', largest unused for 'D'
 * @approach Track low and high bounds; assign accordingly for each character
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> diStringMatch(const string& s) {
        const int n = static_cast<int>(s.size());
        int low = 0, high = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = low++;
            } else {
                ans[i] = high--;
            }
        }
        ans[n] = low;
        return ans;
    }
};
