/**
 * @brief Find maximum XOR of any two numbers in array
 * @intuition Use trie to store binary representations, maximize XOR by taking opposite bits
 * @approach Insert each number into trie, query for maximum XOR with opposite path
 * @complexity Time: O(n * 31) Space: O(n * 31)
 */
#include <algorithm>
#include <array>
#include <vector>

class Trie final {
public:
    std::array<Trie*, 2> children{nullptr, nullptr};

    auto insert(int x) -> void {
        Trie* node = this;
        for (int i = 30; i >= 0; --i) {
            const int v = (x >> i) & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
        }
    }

    [[nodiscard]] auto search(int x) const -> int {
        const Trie* node = this;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            const int v = (x >> i) & 1;
            if (node->children[v ^ 1]) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }
};

class Solution final {
public:
    [[nodiscard]] auto findMaximumXOR(std::vector<int>& nums) const -> int {
        Trie trie;
        int ans = 0;

        for (const int x : nums) {
            trie.insert(x);
            ans = std::max(ans, trie.search(x));
        }

        return ans;
    }
};
