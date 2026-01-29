/**
 * @brief Construct quad tree from 2D grid
 * @intuition If region is uniform, create leaf; otherwise divide into 4 quadrants
 * @approach Recursively check uniformity, subdivide if not uniform
 * @complexity Time: O(n^2 log n) Space: O(log n) recursion
 */
#include <vector>

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution final {
public:
    [[nodiscard]] auto construct(std::vector<std::vector<int>>& grid) const -> Node* {
        return dfs(0, 0, static_cast<int>(grid.size()) - 1, static_cast<int>(grid[0].size()) - 1, grid);
    }

private:
    [[nodiscard]] auto dfs(int a, int b, int c, int d, const std::vector<std::vector<int>>& grid) const -> Node* {
        int zero = 0;
        int one = 0;

        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                if (grid[i][j]) {
                    one = 1;
                } else {
                    zero = 1;
                }
            }
        }

        const bool isLeaf = (zero + one == 1);
        const bool val = isLeaf && one;
        auto* node = new Node(val, isLeaf);

        if (isLeaf) {
            return node;
        }

        node->topLeft = dfs(a, b, (a + c) / 2, (b + d) / 2, grid);
        node->topRight = dfs(a, (b + d) / 2 + 1, (a + c) / 2, d, grid);
        node->bottomLeft = dfs((a + c) / 2 + 1, b, c, (b + d) / 2, grid);
        node->bottomRight = dfs((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, grid);

        return node;
    }
};
