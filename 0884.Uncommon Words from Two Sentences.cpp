/**
 * @brief Find words appearing exactly once across both sentences
 * @intuition Uncommon word appears exactly once in total from both sentences
 * @approach Parse both sentences, count word frequencies. Return words with count 1.
 * @complexity Time: O(n + m), Space: O(n + m)
 */
class Solution final {
public:
    [[nodiscard]] static auto uncommonFromSentences(const std::string& s1,
                                                     const std::string& s2)
        -> std::vector<std::string> {
        std::unordered_map<std::string, int> cnt;
        
        auto addWords = [&](const std::string& s) {
            std::istringstream ss(s);
            std::string w;
            while (ss >> w) {
                ++cnt[std::move(w)];
            }
        };
        
        addWords(s1);
        addWords(s2);
        
        std::vector<std::string> ans;
        for (const auto& [word, count] : cnt) {
            if (count == 1) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
