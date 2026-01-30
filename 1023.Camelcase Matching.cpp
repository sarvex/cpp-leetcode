/**
 * @brief Pattern matching with lowercase flexibility
 * @intuition Pattern chars must appear in order; extra lowercase allowed
 * @approach Two-pointer matching, skip lowercase in query, fail on uppercase mismatch
 * @complexity Time: O(n * m) where n = queries, m = max query length, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<bool> camelMatch(const vector<string>& queries, const string& pattern) {
        vector<bool> ans;
        auto check = [](const string& s, const string& t) {
            const int m = s.size(), n = t.size();
            int i = 0, j = 0;
            for (; j < n; ++i, ++j) {
                while (i < m && s[i] != t[j] && islower(s[i])) {
                    ++i;
                }
                if (i == m || s[i] != t[j]) {
                    return false;
                }
            }
            while (i < m && islower(s[i])) {
                ++i;
            }
            return i == m;
        };
        for (const auto& q : queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }
};
