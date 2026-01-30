/**
 * @brief Multiple stacks with fixed capacity and efficient push/pop operations
 * @intuition Track non-full stacks in sorted set for O(log n) push to leftmost available
 * @approach Use vector of stacks. Maintain set of indices with available capacity.
 *           Push to leftmost non-full stack, pop from specific index or rightmost non-empty.
 * @complexity Time: O(log n) per operation, Space: O(total elements)
 */
class DinnerPlates final {
public:
    DinnerPlates(int capacity) : capacity(capacity) {}

    void push(int val) {
        if (notFull.empty()) {
            stacks.emplace_back(stack<int>());
            stacks.back().push(val);
            if (capacity > 1) {
                notFull.insert(stacks.size() - 1);
            }
        } else {
            int index = *notFull.begin();
            stacks[index].push(val);
            if (stacks[index].size() == capacity) {
                notFull.erase(index);
            }
        }
    }

    [[nodiscard]] int pop() {
        return popAtStack(stacks.size() - 1);
    }

    [[nodiscard]] int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty()) {
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        if (index == stacks.size() - 1 && stacks[index].empty()) {
            while (!stacks.empty() && stacks.back().empty()) {
                notFull.erase(stacks.size() - 1);
                stacks.pop_back();
            }
        } else {
            notFull.insert(index);
        }
        return val;
    }

private:
    size_t capacity;
    vector<stack<int>> stacks;
    set<int> notFull;
};
