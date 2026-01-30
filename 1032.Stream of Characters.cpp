/**
 * @brief Trie with reversed word insertion for suffix matching
 * @intuition Store words reversed in trie; search from end of stream backwards
 * @approach Insert reversed words, check if any word suffix matches stream end
 * @complexity Time: O(W * L) for construction, O(L) per query, Space: O(W * L)
 */
class Trie final {
private:
    Trie* children[26]{};
    bool isEnd = false;

public:
    void insert(string& w) {
        Trie* node = this;
        reverse(w.begin(), w.end());
        for (const char c : w) {
            const int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    [[nodiscard]] bool search(const string& w) const {
        const Trie* node = this;
        for (int i = w.size() - 1, j = 0; i >= 0 && j < 201; --i, ++j) {
            const int idx = w[i] - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
            if (node->isEnd) {
                return true;
            }
        }
        return false;
    }
};

class StreamChecker final {
public:
    Trie* trie = new Trie();
    string s;

    explicit StreamChecker(vector<string>& words) {
        for (auto& w : words) {
            trie->insert(w);
        }
    }

    [[nodiscard]] bool query(const char letter) {
        s += letter;
        return trie->search(s);
    }
};
