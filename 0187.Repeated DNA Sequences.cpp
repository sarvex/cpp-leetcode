/**
 * @brief Find 10-letter DNA sequences appearing more than once
 * @intuition Use hash map to count substring occurrences
 * @approach Sliding window of size 10, track counts in hash map
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto findRepeatedDnaSequences(const std::string& s) -> std::vector<std::string> {
        if (s.size() < 10) {
            return {};
        }
        
        std::unordered_map<std::string, int> counts;
        std::vector<std::string> result;
        
        const int limit = static_cast<int>(s.size()) - 10 + 1;
        for (int i = 0; i < limit; ++i) {
            std::string seq = s.substr(i, 10);
            if (++counts[seq] == 2) {
                result.emplace_back(std::move(seq));
            }
        }
        
        return result;
    }
};
