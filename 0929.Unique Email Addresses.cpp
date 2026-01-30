/**
 * @brief Count unique email addresses after applying rules
 * @intuition Normalize local name: ignore dots and everything after +
 * @approach Parse each email, build normalized form, use set for uniqueness
 * @complexity Time: O(n * m), Space: O(n * m)
 */
class Solution final {
public:
    [[nodiscard]] static int numUniqueEmails(const vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails) {
            const size_t atPos = email.find('@');
            const string local = email.substr(0, atPos);
            const string domain = email.substr(atPos + 1);
            string t;
            for (const char c : local) {
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    break;
                }
                t.push_back(c);
            }
            s.insert(t + "@" + domain);
        }
        return static_cast<int>(s.size());
    }
};
