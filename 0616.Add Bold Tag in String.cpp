/**
 * @brief Add bold tags around substrings matching dictionary words
 * @intuition Use Trie to find all matching intervals, merge overlapping intervals
 * @approach Build Trie from words, find all match intervals, merge and wrap with tags
 * @complexity Time: O(n^2 + m*k) where m is number of words, k is word length, Space: O(m*k)
 */
class Trie final {
public:
    Trie() {
        children_.resize(128);
    }

    void insert(const string& word) {
        Trie* node = this;
        for (const char c : word) {
            if (!node->children_[c]) {
                node->children_[c] = new Trie();
            }
            node = node->children_[c];
        }
        node->isEnd_ = true;
    }

    vector<Trie*> children_;
    bool isEnd_ = false;
};

class Solution final {
public:
    [[nodiscard]] static string addBoldTag(const string& s, const vector<string>& words) {
        auto* trie = new Trie();
        for (const auto& w : words) {
            trie->insert(w);
        }
        
        const int n = s.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                const int idx = s[j];
                if (!node->children_[idx]) {
                    break;
                }
                node = node->children_[idx];
                if (node->isEnd_) {
                    pairs.emplace_back(i, j);
                }
            }
        }
        
        if (pairs.empty()) {
            return s;
        }
        
        vector<pair<int, int>> t;
        int st = pairs[0].first, ed = pairs[0].second;
        for (size_t i = 1; i < pairs.size(); ++i) {
            const auto [a, b] = pairs[i];
            if (ed + 1 < a) {
                t.emplace_back(st, ed);
                st = a;
                ed = b;
            } else {
                ed = max(ed, b);
            }
        }
        t.emplace_back(st, ed);
        
        string ans;
        int i = 0;
        size_t j = 0;
        while (i < n) {
            if (j == t.size()) {
                ans += s.substr(i);
                break;
            }
            st = t[j].first;
            ed = t[j].second;
            if (i < st) {
                ans += s.substr(i, st - i);
            }
            ans += "<b>";
            ans += s.substr(st, ed - st + 1);
            ans += "</b>";
            i = ed + 1;
            ++j;
        }
        return ans;
    }
};
