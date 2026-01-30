/**
 * @brief Find most frequent word excluding banned words
 * @intuition Parse words, normalize case, count frequencies, skip banned
 * @approach Iterate through paragraph extracting alphabetic words to lowercase.
 *           Use hash set for O(1) banned check, hash map for counting.
 *           Track maximum frequency word during iteration.
 * @complexity Time: O(n + b), Space: O(n + b) where b is banned list size
 */
class Solution final {
public:
    [[nodiscard]] static auto mostCommonWord(const std::string& paragraph,
                                              const std::vector<std::string>& banned)
        -> std::string {
        std::unordered_set<std::string> s(banned.begin(), banned.end());
        std::unordered_map<std::string, int> counter;
        std::string ans;
        const int n = static_cast<int>(paragraph.size());
        int mx = 0;
        
        for (int i = 0; i < n;) {
            if (!std::isalpha(paragraph[i])) {
                ++i;
                continue;
            }
            
            std::string word;
            while (i < n && std::isalpha(paragraph[i])) {
                word.push_back(std::tolower(paragraph[i]));
                ++i;
            }
            
            if (s.count(word)) continue;
            
            ++counter[word];
            if (counter[word] > mx) {
                ans = word;
                mx = counter[word];
            }
        }
        return ans;
    }
};
