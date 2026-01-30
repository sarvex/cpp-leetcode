/**
 * @brief Simultaneous string replacements at given indices
 * @intuition Replacements don't interfere if processed independently per index
 * @approach Mark valid replacement indices, then build result string. Skip
 *           source length chars when replacement occurs, otherwise copy original.
 * @complexity Time: O(n * m) where m is max source length, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findReplaceString(const std::string& s,
                                                 const std::vector<int>& indices,
                                                 const std::vector<std::string>& sources,
                                                 const std::vector<std::string>& targets)
        -> std::string {
        const int n = static_cast<int>(s.size());
        std::vector<int> d(n, -1);
        
        for (int k = 0; k < static_cast<int>(indices.size()); ++k) {
            const int i = indices[k];
            if (s.compare(i, sources[k].size(), sources[k]) == 0) {
                d[i] = k;
            }
        }
        
        std::string ans;
        for (int i = 0; i < n;) {
            if (d[i] != -1) {
                ans += targets[d[i]];
                i += static_cast<int>(sources[d[i]].size());
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};
