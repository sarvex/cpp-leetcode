/**
 * @brief Iterator to flatten nested list
 * @intuition Flatten all nested integers into a simple vector
 * @approach DFS to flatten at construction, then iterate linearly
 * @complexity Time: O(n) flatten, O(1) next/hasNext, Space: O(n)
 */
#include <vector>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator final {
public:
    explicit NestedIterator(std::vector<NestedInteger>& nestedList) {
        auto dfs = [&](this auto&& dfs, std::vector<NestedInteger>& list) -> void {
            for (auto& item : list) {
                if (item.isInteger()) {
                    nums_.push_back(item.getInteger());
                } else {
                    dfs(item.getList());
                }
            }
        };
        dfs(nestedList);
    }

    [[nodiscard]] int next() {
        return nums_[++index_];
    }

    [[nodiscard]] bool hasNext() const {
        return index_ + 1 < static_cast<int>(nums_.size());
    }

private:
    std::vector<int> nums_;
    int index_ = -1;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
