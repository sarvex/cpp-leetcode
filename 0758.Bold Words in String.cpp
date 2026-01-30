/**
 * @brief Bold words in string using Trie for matching
 * @intuition Find all word occurrences, merge overlapping ranges, wrap with <b> tags
 * @approach Trie for efficient prefix matching, interval merging for bold ranges
 * @complexity Time: O(n * L + m) where L is max word length, m is total word chars, Space: O(m)
 */
class Solution final {
    struct Trie {
        std::array<Trie*, 128> children{};
        bool isEnd = false;

        void insert(const std::string& word) {
            Trie* node = this;
            for (const char c : word) {
                if (!node->children[c]) {
                    node->children[c] = new Trie();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
    };

public:
    [[nodiscard]] static std::string boldWords(const std::vector<std::string>& words, 
                                                const std::string& s) {
        Trie trie;
        for (const auto& word : words) {
            trie.insert(word);
        }
        
        const int n = static_cast<int>(s.size());
        std::vector<std::pair<int, int>> matches;
        
        for (int i = 0; i < n; ++i) {
            Trie* node = &trie;
            for (int j = i; j < n; ++j) {
                if (!node->children[s[j]]) break;
                node = node->children[s[j]];
                if (node->isEnd) {
                    matches.emplace_back(i, j);
                }
            }
        }
        
        if (matches.empty()) return s;
        
        std::vector<std::pair<int, int>> merged;
        int start = matches[0].first;
        int end = matches[0].second;
        
        for (size_t i = 1; i < matches.size(); ++i) {
            if (end + 1 < matches[i].first) {
                merged.emplace_back(start, end);
                start = matches[i].first;
                end = matches[i].second;
            } else {
                end = std::max(end, matches[i].second);
            }
        }
        merged.emplace_back(start, end);
        
        std::string result;
        int pos = 0;
        for (const auto& [st, ed] : merged) {
            if (pos < st) {
                result += s.substr(pos, st - pos);
            }
            result += "<b>" + s.substr(st, ed - st + 1) + "</b>";
            pos = ed + 1;
        }
        if (pos < n) {
            result += s.substr(pos);
        }
        return result;
    }
};
