/**
 * @brief Trie-based word encoding with suffix sharing
 * @intuition Words sharing suffixes can be encoded together; use reverse trie
 * @approach Build trie inserting words in reverse (for suffix matching).
 *           Only leaf nodes contribute to encoding length. DFS to sum all
 *           leaf depths (each leaf adds depth + 1 for '#' terminator).
 * @complexity Time: O(sum of word lengths), Space: O(sum of word lengths)
 */
class Solution final {
    struct Trie {
        std::array<Trie*, 26> children{};
    };
    
    [[nodiscard]] static auto dfs(const Trie* cur, int depth) -> int {
        bool isLeaf = true;
        int ans = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (cur->children[i] != nullptr) {
                isLeaf = false;
                ans += dfs(cur->children[i], depth + 1);
            }
        }
        
        return isLeaf ? depth : ans;
    }

public:
    [[nodiscard]] static auto minimumLengthEncoding(
        const std::vector<std::string>& words) -> int {
        auto* root = new Trie();
        
        for (const auto& w : words) {
            auto* cur = root;
            for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
                const int idx = w[i] - 'a';
                if (cur->children[idx] == nullptr) {
                    cur->children[idx] = new Trie();
                }
                cur = cur->children[idx];
            }
        }
        return dfs(root, 1);
    }
};
