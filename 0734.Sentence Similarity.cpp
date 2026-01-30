/**
 * @brief Check sentence similarity using hash set
 * @intuition Words are similar if equal or directly listed as similar pair
 * @approach Store bidirectional pairs in set, check each word pair
 * @complexity Time: O(n + p) where p is pairs count, Space: O(p)
 */
class Solution final {
public:
    [[nodiscard]] static bool areSentencesSimilar(
            const std::vector<std::string>& sentence1,
            const std::vector<std::string>& sentence2,
            const std::vector<std::vector<std::string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        
        std::unordered_set<std::string> pairSet;
        for (const auto& pair : similarPairs) {
            pairSet.insert(pair[0] + "#" + pair[1]);
            pairSet.insert(pair[1] + "#" + pair[0]);
        }
        
        for (size_t i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] != sentence2[i] && 
                !pairSet.contains(sentence1[i] + "#" + sentence2[i])) {
                return false;
            }
        }
        return true;
    }
};
