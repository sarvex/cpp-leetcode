/**
 * @brief Find 10-letter DNA sequences appearing more than once
 * @intuition Use hash map to count substring occurrences
 * @approach Sliding window of size 10, track counts in hash map
 * @complexity Time: O(n), Space: O(n)
 */

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto findRepeatedDnaSequences(const string& s) const -> vector<string> {
        if (s.size() < 10) {
            return {};
        }
        
        unordered_map<string, int> counts;
        vector<string> result;
        
        const int limit = static_cast<int>(s.size()) - 10 + 1;
        for (int i = 0; i < limit; ++i) {
            string seq = s.substr(i, 10);
            if (++counts[seq] == 2) {
                result.emplace_back(std::move(seq));
            }
        }
        
        return result;
    }
};
