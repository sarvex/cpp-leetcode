/**
 * @brief Count substrings with equal consecutive 0s and 1s
 * @intuition Group consecutive same chars, pairs contribute min of adjacent group sizes
 * @approach Count consecutive groups, sum min of adjacent pair lengths
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int countBinarySubstrings(const string& s) {
        const int n = s.size();
        vector<int> t;
        int i = 0;
        
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i + 1] == s[i]) {
                ++cnt;
                ++i;
            }
            t.push_back(cnt);
            ++i;
        }
        
        int ans = 0;
        for (size_t j = 1; j < t.size(); ++j) {
            ans += min(t[j - 1], t[j]);
        }
        return ans;
    }
};
