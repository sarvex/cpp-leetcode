/**
 * @brief Trie with wildcard search using DFS
 * @intuition Trie enables prefix matching, DFS handles '.' wildcards
 * @approach Build trie for words, recursively search with wildcard branching
 * @complexity Time: O(m) for add, O(26^m) worst case for search, Space: O(n*m)
 */

class TrieNode final {
public:
    std::array<std::unique_ptr<TrieNode>, 26> children{};
    bool isEnd = false;

    auto insert(const std::string& word) -> void {
        TrieNode* current = this;
        for (const char c : word) {
            const int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = std::make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->isEnd = true;
    }
};

class WordDictionary final {
private:
    std::unique_ptr<TrieNode> root;

    [[nodiscard]] auto dfs(const std::string& word, std::size_t index, const TrieNode* node) const -> bool {
        if (index == word.size()) {
            return node->isEnd;
        }
        const char c = word[index];
        if (c != '.') {
            const auto* child = node->children[c - 'a'].get();
            return child != nullptr && dfs(word, index + 1, child);
        }
        for (const auto& child : node->children) {
            if (child && dfs(word, index + 1, child.get())) {
                return true;
            }
        }
        return false;
    }

public:
    WordDictionary() : root(std::make_unique<TrieNode>()) {}

    auto addWord(const std::string& word) -> void {
        root->insert(word);
    }

    [[nodiscard]] auto search(const std::string& word) const -> bool {
        return dfs(word, 0, root.get());
    }
};
