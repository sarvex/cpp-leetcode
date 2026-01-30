/**
 * @brief Partition string into maximum parts where each char appears in one part
 * @intuition Each partition must extend to last occurrence of any char it contains
 * @approach Track last index of each char, greedily extend partition boundaries
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> partitionLabels(const std::string& s) {
        std::array<int, 26> lastIndex{};
        const int n = static_cast<int>(s.size());
        
        for (int i = 0; i < n; ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        std::vector<int> result;
        int partitionEnd = 0;
        int partitionStart = 0;
        
        for (int i = 0; i < n; ++i) {
            partitionEnd = std::max(partitionEnd, lastIndex[s[i] - 'a']);
            if (partitionEnd == i) {
                result.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return result;
    }
};
