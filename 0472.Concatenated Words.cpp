/**
 * @brief Find all concatenated words (formed by other words in list)
 * @intuition Use trie to check if word can be split into dictionary words
 * @approach Sort by length, for each word check if it's concatenated, then insert
 * @complexity Time: O(n * L^2) where L is max word length, Space: O(n * L)
 */
#include <algorithm>
#include <string>
#include <vector>

class Trie final {
public:
    std::vector<Trie*> children;
    bool isEnd;

    Trie() : children(26, nullptr), isEnd(false) {}

    auto insert(const std::string& w) -> void {
        Trie* node = this;
        for (const char c : w) {
            const int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};

class Solution final {
public:
    [[nodiscard]] auto findAllConcatenatedWordsInADict(std::vector<std::string>& words) const
        -> std::vector<std::string> {
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });

        Trie trie;
        std::vector<std::string> ans;

        for (const auto& w : words) {
            if (dfs(w, &trie)) {
                ans.push_back(w);
            } else {
                trie.insert(w);
            }
        }

        return ans;
    }

private:
    [[nodiscard]] auto dfs(const std::string& w, Trie* trie) const -> bool {
        if (w.empty()) {
            return true;
        }

        Trie* node = trie;
        for (std::size_t i = 0; i < w.size(); ++i) {
            const int idx = w[i] - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
            if (node->isEnd && dfs(w.substr(i + 1), trie)) {
                return true;
            }
        }

        return false;
    }
};
