/**
 * @brief Stack supporting O(1) min retrieval using auxiliary stack
 * @intuition Maintain parallel stack tracking minimum at each level
 * @approach Push to min stack only when new min encountered
 * @complexity Time: O(1) all operations, Space: O(n)
 */

class MinStack final {
private:
    std::stack<int> data_;
    std::stack<int> minStack_;
    
public:
    MinStack() {
        minStack_.push(std::numeric_limits<int>::max());
    }
    
    auto push(int val) -> void {
        data_.push(val);
        minStack_.push(std::min(val, minStack_.top()));
    }
    
    auto pop() -> void {
        data_.pop();
        minStack_.pop();
    }
    
    [[nodiscard]] auto top() const -> int {
        return data_.top();
    }
    
    [[nodiscard]] auto getMin() const -> int {
        return minStack_.top();
    }
};
