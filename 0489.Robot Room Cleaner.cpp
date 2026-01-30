/**
 * @brief Clean entire room using robot with move/turn/clean operations
 * @intuition DFS backtracking: explore all directions, return to start
 * @approach Track visited cells, for each cell try all 4 directions
 * @complexity Time: O(n - m) where n is cells, m is obstacles, Space: O(n - m)
 */
#include <functional>
#include <set>
#include <utility>

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution final {
public:
    auto cleanRoom(Robot& robot) const -> void {
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        std::set<std::pair<int, int>> visited;

        std::function<void(int, int, int)> dfs = [&](int row, int col, int dir) {
            robot.clean();
            visited.insert({row, col});

            for (int k = 0; k < 4; ++k) {
                const int newDir = (dir + k) % 4;
                const int newRow = row + dirs[newDir];
                const int newCol = col + dirs[newDir + 1];

                if (!visited.contains({newRow, newCol}) && robot.move()) {
                    dfs(newRow, newCol, newDir);
                    robot.turnRight();
                    robot.turnRight();
                    robot.move();
                    robot.turnRight();
                    robot.turnRight();
                }
                robot.turnRight();
            }
        };

        dfs(0, 0, 0);
    }
};
