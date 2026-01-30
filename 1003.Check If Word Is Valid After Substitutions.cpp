/**
 * @brief Stack-based pattern matching for "abc" removal
 * @intuition Continuously remove "abc" substrings until empty or impossible
 * @approach Build string character by character, remove "abc" when found at end
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool isValid(const std::string& s) {
        if (s.size() % 3) {
            return false;
        }
        std::string t;
        for (const char c : s) {
            t.push_back(c);
            if (t.size() >= 3 && t.substr(t.size() - 3, 3) == "abc") {
                t.erase(t.end() - 3, t.end());
            }
        }
        return t.empty();
    }
};
