/**
 * @brief Find lexicographically largest string from concatenated loop
 * @intuition Each string can be normal or reversed; try all split points
 * @approach Pre-reverse strings to max form, then try each string at each position as start
 * @complexity Time: O(n * L^2), Space: O(L) where L is total length
 */
class Solution final {
public:
    [[nodiscard]] static string splitLoopedString(vector<string>& strs) {
        for (auto& s : strs) {
            string t{s.rbegin(), s.rend()};
            s = max(s, t);
        }
        
        const int n = static_cast<int>(strs.size());
        string ans;
        
        for (int i = 0; i < n; ++i) {
            auto& s = strs[i];
            string tail;
            
            for (int j = i + 1; j < n; ++j) {
                tail += strs[j];
            }
            for (int j = 0; j < i; ++j) {
                tail += strs[j];
            }
            
            for (size_t j = 0; j < s.size(); ++j) {
                auto prefix = s.substr(j);
                auto suffix = s.substr(0, j);
                auto cur = prefix + tail + suffix;
                
                if (ans < cur) {
                    ans = cur;
                }
                
                reverse(prefix.begin(), prefix.end());
                reverse(suffix.begin(), suffix.end());
                cur = suffix + tail + prefix;
                
                if (ans < cur) {
                    ans = cur;
                }
            }
        }
        
        return ans;
    }
};
