/**
 * @brief Trie-based file system for path creation and value retrieval
 * @intuition Use trie where each node represents a path component
 * @approach Split paths by '/'. For create, verify parent exists before adding new node.
 *           For get, traverse trie following path components.
 * @complexity Time: O(path length) per operation, Space: O(total path components)
 */
class Trie final {
public:
    unordered_map<string, Trie*> children;
    int v;

    Trie(int v) : v(v) {}

    [[nodiscard]] bool insert(const string& w, int val) {
        Trie* node = this;
        auto ps = split(w, '/');
        for (size_t i = 1; i < ps.size() - 1; ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return false;
            }
            node = node->children[p];
        }
        if (node->children.count(ps.back())) {
            return false;
        }
        node->children[ps.back()] = new Trie(val);
        return true;
    }

    [[nodiscard]] int search(const string& w) const {
        const Trie* node = this;
        auto ps = split(w, '/');
        for (size_t i = 1; i < ps.size(); ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return -1;
            }
            node = node->children.at(p);
        }
        return node->v;
    }

private:
    [[nodiscard]] static vector<string> split(const string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};

class FileSystem final {
public:
    FileSystem() : trie(new Trie(-1)) {}

    [[nodiscard]] bool createPath(const string& path, int value) {
        return trie->insert(path, value);
    }

    [[nodiscard]] int get(const string& path) const {
        return trie->search(path);
    }

private:
    Trie* trie;
};
