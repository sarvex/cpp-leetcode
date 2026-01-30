/**
 * @brief Iterator to flatten nested list
 * @intuition Flatten all nested integers into a simple vector
 * @approach DFS to flatten at construction, then iterate linearly
 * @complexity Time: O(n) flatten, O(1) next/hasNext, Space: O(n)
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
