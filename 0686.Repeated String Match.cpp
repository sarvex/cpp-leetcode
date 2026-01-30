/**
 * @brief Minimum repetitions of a such that b is substring
 * @intuition At least ceil(len(b)/len(a)) copies needed, at most +2 more
 * @approach Try minimum repetitions, add up to 2 more if not found
 * @complexity Time: O(n * m), Space: O(n * m) for concatenated string
 */
class Solution final {
public:
    [[nodiscard]] static int repeatedStringMatch(const string& a, const string& b) {
        const int m = a.size(), n = b.size();
        int ans = (n + m - 1) / m;
        string t;
        
        for (int i = 0; i < ans; ++i) {
            t += a;
        }
        
        for (int i = 0; i < 3; ++i) {
            if (t.find(b) != string::npos) {
                return ans;
            }
            ++ans;
            t += a;
        }
        return -1;
    }
};
