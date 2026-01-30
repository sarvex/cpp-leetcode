/**
 * @brief Map with prefix sum functionality
 * @intuition Use Trie storing cumulative sums along paths, adjust for updates
 * @approach Trie nodes store sum of all values with that prefix
 * @complexity Time: O(m) for insert/sum, Space: O(n*m)
 */
class Trie final {
public:
    Trie() : children_(26, nullptr) {}

    void insert(const string& w, const int x) {
        Trie* node = this;
        for (const char c : w) {
            const int i = c - 'a';
            if (!node->children_[i]) {
                node->children_[i] = new Trie();
            }
            node = node->children_[i];
            node->val_ += x;
        }
    }

    [[nodiscard]] int search(const string& w) const {
        const Trie* node = this;
        for (const char c : w) {
            const int i = c - 'a';
            if (!node->children_[i]) {
                return 0;
            }
            node = node->children_[i];
        }
        return node->val_;
    }

private:
    vector<Trie*> children_;
    int val_ = 0;
};

class MapSum final {
public:
    MapSum() : trie_(new Trie()) {}

    void insert(const string& key, const int val) {
        const int x = val - d_[key];
        d_[key] = val;
        trie_->insert(key, x);
    }

    [[nodiscard]] int sum(const string& prefix) const {
        return trie_->search(prefix);
    }

private:
    unordered_map<string, int> d_;
    Trie* trie_;
};
