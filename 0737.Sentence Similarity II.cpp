/**
 * @brief Check sentence similarity with transitivity using Union-Find
 * @intuition Transitive similarity forms connected components
 * @approach Union-Find to group similar words, check if word pairs share root
 * @complexity Time: O(n + p*α(p)), Space: O(p) where p is pairs count
 */
class Solution final {
public:
    [[nodiscard]] bool areSentencesSimilarTwo(
            const std::vector<std::string>& sentence1,
            const std::vector<std::string>& sentence2,
            const std::vector<std::vector<std::string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        
        const int n = static_cast<int>(similarPairs.size());
        parent_.resize(n << 1);
        std::iota(parent_.begin(), parent_.end(), 0);
        
        std::unordered_map<std::string, int> wordToId;
        int idx = 0;
        
        for (const auto& pair : similarPairs) {
            if (!wordToId.contains(pair[0])) {
                wordToId[pair[0]] = idx++;
            }
            if (!wordToId.contains(pair[1])) {
                wordToId[pair[1]] = idx++;
            }
            parent_[find(wordToId[pair[0]])] = find(wordToId[pair[1]]);
        }
        
        for (size_t i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (!wordToId.contains(sentence1[i]) || !wordToId.contains(sentence2[i]) ||
                find(wordToId[sentence1[i]]) != find(wordToId[sentence2[i]])) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<int> parent_;

    [[nodiscard]] int find(const int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }
};
