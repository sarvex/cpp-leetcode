/**
 * @brief Solve sliding puzzle with minimum moves using BFS
 * @intuition BFS explores states level by level, finding shortest path
 * @approach Encode board as string, BFS through valid swaps
 * @complexity Time: O(6!), Space: O(6!)
 */
class Solution final {
public:
    [[nodiscard]] static int slidingPuzzle(std::vector<std::vector<int>>& board) {
        const std::string start = boardToString(board);
        const std::string target = "123450";
        if (start == target) return 0;
        
        std::unordered_set<std::string> visited{start};
        std::queue<std::string> queue;
        queue.push(start);
        int moves = 0;
        
        while (!queue.empty()) {
            ++moves;
            for (int sz = static_cast<int>(queue.size()); sz > 0; --sz) {
                std::string current = queue.front();
                queue.pop();
                stringToBoard(current, board);
                
                for (const auto& next : getNeighbors(board)) {
                    if (next == target) return moves;
                    if (!visited.contains(next)) {
                        visited.insert(next);
                        queue.push(next);
                    }
                }
            }
        }
        return -1;
    }

private:
    [[nodiscard]] static std::string boardToString(const std::vector<std::vector<int>>& board) {
        std::string s;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                s += static_cast<char>('0' + board[i][j]);
            }
        }
        return s;
    }

    static void stringToBoard(const std::string& s, std::vector<std::vector<int>>& board) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = s[i * 3 + j] - '0';
            }
        }
    }

    [[nodiscard]] static std::vector<std::string> getNeighbors(std::vector<std::vector<int>>& board) {
        std::vector<std::string> result;
        auto [zeroRow, zeroCol] = findZero(board);
        constexpr std::array<int, 5> dirs{-1, 0, 1, 0, -1};
        
        for (int k = 0; k < 4; ++k) {
            const int x = zeroRow + dirs[k];
            const int y = zeroCol + dirs[k + 1];
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                std::swap(board[zeroRow][zeroCol], board[x][y]);
                result.push_back(boardToString(board));
                std::swap(board[zeroRow][zeroCol], board[x][y]);
            }
        }
        return result;
    }

    [[nodiscard]] static std::pair<int, int> findZero(const std::vector<std::vector<int>>& board) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};
