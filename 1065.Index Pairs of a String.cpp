/**
 * @brief Trie-based word matching in text
 * @intuition Build trie from words; scan text finding all word matches
 * @approach Insert words into trie, for each position traverse trie collecting matches
 * @complexity Time: O(n * m + sum of word lengths), Space: O(sum of word lengths)
 */
class Trie final {
public:
    array<Trie*, 26> children{};
    bool isEnd = false;

    void insert(const string& word) {
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
};

class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> indexPairs(const string& text, const vector<string>& words) {
        auto* trie = new Trie();
        for (const auto& w : words) {
            trie->insert(w);
        }
        const int n = text.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                const int idx = text[j] - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
