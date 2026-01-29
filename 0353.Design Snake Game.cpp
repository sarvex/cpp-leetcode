/**
 * @brief Design Snake game with food and collision detection
 * @intuition Use deque for snake body, set for O(1) collision check
 * @approach Track snake position with deque, check bounds and self-collision
 * @complexity Time: O(1) per move, Space: O(snake length)
 */
#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

class SnakeGame final {
public:
    SnakeGame(int width, int height, std::vector<std::vector<int>>& food)
        : width_(width), height_(height), food_(food) {
        snake_.push_back(0);
        occupied_.insert(0);
    }

    [[nodiscard]] int move(const std::string& direction) {
        const int head = snake_.front();
        int row = head / width_;
        int col = head % width_;
        
        if (direction == "U") {
            --row;
        } else if (direction == "D") {
            ++row;
        } else if (direction == "L") {
            --col;
        } else {
            ++col;
        }
        
        // Check boundaries
        if (row < 0 || row >= height_ || col < 0 || col >= width_) {
            return -1;
        }
        
        // Check if eating food
        if (foodIndex_ < static_cast<int>(food_.size()) && 
            row == food_[foodIndex_][0] && col == food_[foodIndex_][1]) {
            ++score_;
            ++foodIndex_;
        } else {
            // Remove tail
            const int tail = snake_.back();
            snake_.pop_back();
            occupied_.erase(tail);
        }
        
        // Check self-collision
        const int newHead = row * width_ + col;
        if (occupied_.contains(newHead)) {
            return -1;
        }
        
        snake_.push_front(newHead);
        occupied_.insert(newHead);
        return score_;
    }

private:
    int width_;
    int height_;
    std::vector<std::vector<int>> food_;
    int score_ = 0;
    int foodIndex_ = 0;
    std::deque<int> snake_;
    std::unordered_set<int> occupied_;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
