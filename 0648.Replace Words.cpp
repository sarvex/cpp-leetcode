/**
 * @brief Replace words in sentence with shortest dictionary root
 * @intuition Use Trie to find shortest prefix match for each word
 * @approach Build Trie from dictionary, find shortest root for each word
 * @complexity Time: O(n + m*k) where m is dictionary size, k is word length, Space: O(m*k)
 */
class Trie final {
public:
    Trie() {
        memset(children_, 0, sizeof(children_));
    }

    void insert(const string& w, const int i) {
        Trie* node = this;
        for (const char c : w) {
            const int idx = c - 'a';
            if (!node->children_[idx]) {
                node->children_[idx] = new Trie();
            }
            node = node->children_[idx];
        }
        node->ref_ = i;
    }

    [[nodiscard]] int search(const string& w) const {
        const Trie* node = this;
        for (const char c : w) {
            const int idx = c - 'a';
            if (!node->children_[idx]) {
                return -1;
            }
            node = node->children_[idx];
            if (node->ref_ != -1) {
                return node->ref_;
            }
        }
        return -1;
    }

private:
    Trie* children_[26];
    int ref_ = -1;
};

class Solution final {
public:
    [[nodiscard]] static string replaceWords(const vector<string>& dictionary, const string& sentence) {
        auto* trie = new Trie();
        for (size_t i = 0; i < dictionary.size(); ++i) {
            trie->insert(dictionary[i], i);
        }
        
        stringstream ss(sentence);
        string w;
        string ans;
        
        while (ss >> w) {
            const int idx = trie->search(w);
            ans += (idx == -1 ? w : dictionary[idx]) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
