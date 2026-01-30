/**
 * @brief Find nearest palindrome by trying candidate transformations
 * @intuition Candidates: mirror left half (with +/-1), or 10^(n-1)-1, 10^n+1
 * @approach Generate all candidates, pick closest (smaller wins ties), exclude self
 * @complexity Time: O(d), Space: O(d) where d is number of digits
 */
class Solution final {
public:
    [[nodiscard]] static string nearestPalindromic(const string& n) {
        const long x = stol(n);
        long ans = -1;
        
        for (const long candidate : getCandidates(n)) {
            if (ans == -1 || 
                abs(candidate - x) < abs(ans - x) || 
                (abs(candidate - x) == abs(ans - x) && candidate < ans)) {
                ans = candidate;
            }
        }
        
        return to_string(ans);
    }

private:
    [[nodiscard]] static unordered_set<long> getCandidates(const string& n) {
        const int len = static_cast<int>(n.size());
        unordered_set<long> result;
        
        result.insert(static_cast<long>(pow(10, len - 1)) - 1);
        result.insert(static_cast<long>(pow(10, len)) + 1);
        
        const long left = stol(n.substr(0, (len + 1) / 2));
        
        for (long i = left - 1; i <= left + 1; ++i) {
            const string prefix = to_string(i);
            const string palindrome = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            result.insert(stol(palindrome));
        }
        
        result.erase(stol(n));
        return result;
    }
};
