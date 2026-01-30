/**
 * @brief Generate minimal unique abbreviations using Trie
 * @intuition Group words by length and last char; use Trie to find minimal unique prefix
 * @approach Build Tries for each (length, last_char) group counting prefix occurrences.
 *           For each word, find shortest prefix with count=1. Generate abbreviation
 *           only if it's shorter than original word.
 * @complexity Time: O(n * L^2), Space: O(n * L)
 */
class Trie final {
public:
    Trie() : cnt(0) {
        fill(children.begin(), children.end(), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            const int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    [[nodiscard]] auto search(const string& w) const -> int {
        const Trie* node = this;
        int len = 0;
        for (char c : w) {
            ++len;
            const int idx = c - 'a';
            node = node->children[idx];
            if (node->cnt == 1) return len;
        }
        return static_cast<int>(w.size());
    }

private:
    array<Trie*, 26> children;
    int cnt;
};

class Solution final {
public:
    [[nodiscard]] static auto wordsAbbreviation(const vector<string>& words) -> vector<string> {
        map<pair<int, int>, Trie*> tries;
        
        for (const auto& w : words) {
            pair<int, int> key = {static_cast<int>(w.size()), w.back() - 'a'};
            if (!tries.contains(key)) {
                tries[key] = new Trie();
            }
            tries[key]->insert(w);
        }

        vector<string> ans;
        ans.reserve(words.size());
        
        for (const auto& w : words) {
            const int m = static_cast<int>(w.size());
            pair<int, int> key = {m, w.back() - 'a'};
            const int prefixLen = tries[key]->search(w);
            
            if (prefixLen + 2 >= m) {
                ans.push_back(w);
            } else {
                ans.push_back(w.substr(0, prefixLen) + to_string(m - prefixLen - 1) + w.back());
            }
        }
        return ans;
    }
};
