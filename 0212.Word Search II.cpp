/**
 * @brief Trie + DFS backtracking for word search on board
 * @intuition Build trie from words, search board using DFS with trie guidance
 * @approach DFS from each cell, prune paths not in trie, mark found words
 * @complexity Time: O(m*n*4^L) where L is max word length, Space: O(W*L) for trie
 */

class Trie final {
public:
    std::array<std::unique_ptr<Trie>, 26> children{};
    int wordIndex = -1;

    auto insert(const std::string& word, int index) -> void {
        Trie* node = this;
        for (const char c : word) {
            const int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = std::make_unique<Trie>();
            }
            node = node->children[idx].get();
        }
        node->wordIndex = index;
    }
};

class Solution final {
public:
    [[nodiscard]] static auto findWords(std::vector<std::vector<char>>& board,
                                        const std::vector<std::string>& words) -> std::vector<std::string> {
        auto trie = std::make_unique<Trie>();
        for (int i = 0; i < static_cast<int>(words.size()); ++i) {
            trie->insert(words[i], i);
        }
        
        std::vector<std::string> result;
        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());
        constexpr std::array<int, 5> directions = {-1, 0, 1, 0, -1};
        
        auto dfs = [&](this auto&& dfs, Trie* node, int row, int col) -> void {
            const int charIndex = board[row][col] - 'a';
            if (!node->children[charIndex]) {
                return;
            }
            node = node->children[charIndex].get();
            if (node->wordIndex != -1) {
                result.push_back(words[node->wordIndex]);
                node->wordIndex = -1;
            }
            const char originalChar = board[row][col];
            board[row][col] = '#';
            for (int k = 0; k < 4; ++k) {
                const int newRow = row + directions[k];
                const int newCol = col + directions[k + 1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && board[newRow][newCol] != '#') {
                    dfs(node, newRow, newCol);
                }
            }
            board[row][col] = originalChar;
        };
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(trie.get(), i, j);
            }
        }
        
        return result;
    }
};
