/**
 * @brief Magic dictionary that searches for words differing by exactly one character
 * @intuition Use Trie to store words, search with exactly one character difference
 * @approach DFS through Trie, track number of mismatches, must be exactly one at end
 * @complexity Time: O(n*m) for build, O(26*m) for search, Space: O(n*m)
 */
class Trie final {
public:
    Trie() {
        fill(begin(children_), end(children_), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (const char c : w) {
            const int i = c - 'a';
            if (!node->children_[i]) {
                node->children_[i] = new Trie();
            }
            node = node->children_[i];
        }
        node->isEnd_ = true;
    }

    [[nodiscard]] bool search(const string& w) const {
        auto dfs = [&](this auto&& dfs, size_t i, const Trie* node, int diff) -> bool {
            if (i >= w.size()) {
                return diff == 1 && node->isEnd_;
            }
            const int j = w[i] - 'a';
            if (node->children_[j] && dfs(i + 1, node->children_[j], diff)) {
                return true;
            }
            if (diff == 0) {
                for (int k = 0; k < 26; ++k) {
                    if (k != j && node->children_[k] && dfs(i + 1, node->children_[k], 1)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }

private:
    Trie* children_[26];
    bool isEnd_ = false;
};

class MagicDictionary final {
public:
    MagicDictionary() : trie_(new Trie()) {}

    void buildDict(const vector<string>& dictionary) {
        for (const auto& w : dictionary) {
            trie_->insert(w);
        }
    }

    [[nodiscard]] bool search(const string& searchWord) const {
        return trie_->search(searchWord);
    }

private:
    Trie* trie_;
};
