/**
 * @brief Longest word buildable one character at a time using Trie
 * @intuition Valid words must have all prefixes present in dictionary
 * @approach Build trie, search verifies each prefix ends a word
 * @complexity Time: O(sum of word lengths), Space: O(sum of word lengths)
 */
class Solution final {
    struct Trie {
        std::array<Trie*, 26> children{};
        bool isEnd = false;

        void insert(const std::string& word) {
            Trie* node = this;
            for (const char c : word) {
                const int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new Trie();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }

        [[nodiscard]] bool search(const std::string& word) const {
            const Trie* node = this;
            for (const char c : word) {
                const int idx = c - 'a';
                if (!node->children[idx] || !node->children[idx]->isEnd) {
                    return false;
                }
                node = node->children[idx];
            }
            return true;
        }
    };

public:
    [[nodiscard]] static std::string longestWord(const std::vector<std::string>& words) {
        Trie trie;
        for (const auto& word : words) {
            trie.insert(word);
        }

        std::string result;
        for (const auto& word : words) {
            if (trie.search(word)) {
                if (result.length() < word.length() || 
                    (result.length() == word.length() && word < result)) {
                    result = word;
                }
            }
        }
        return result;
    }
};
