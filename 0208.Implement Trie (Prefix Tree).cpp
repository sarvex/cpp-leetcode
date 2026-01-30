/**
 * @brief Trie implementation with array-based children
 * @intuition Prefix tree enables efficient string prefix operations
 * @approach Each node has 26 children for lowercase letters and end marker
 * @complexity Time: O(m) for all operations where m is key length, Space: O(n*m)
 */

class Trie final {
private:
    std::array<std::unique_ptr<Trie>, 26> children{};
    bool isEndOfWord = false;

    [[nodiscard]] auto searchPrefix(const std::string& prefix) const -> const Trie* {
        const Trie* node = this;
        for (const char c : prefix) {
            const int index = c - 'a';
            if (!node->children[index]) {
                return nullptr;
            }
            node = node->children[index].get();
        }
        return node;
    }

public:
    Trie() = default;

    auto insert(const std::string& word) -> void {
        Trie* node = this;
        for (const char c : word) {
            const int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = std::make_unique<Trie>();
            }
            node = node->children[index].get();
        }
        node->isEndOfWord = true;
    }

    [[nodiscard]] auto search(const std::string& word) const -> bool {
        const auto* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord;
    }

    [[nodiscard]] auto startsWith(const std::string& prefix) const -> bool {
        return searchPrefix(prefix) != nullptr;
    }
};
