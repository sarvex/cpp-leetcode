/**
 * @brief O(1) Insert/Delete/GetRandom using hash map and vector
 * @intuition Vector for random access, hash map for O(1) index lookup
 * @approach Swap with last element on remove to maintain contiguous array
 * @complexity Time: O(1) average per operation, Space: O(n)
 */
class RandomizedSet final {
public:
    [[nodiscard]] auto insert(int val) -> bool {
        if (indices_.contains(val)) {
            return false;
        }
        indices_[val] = static_cast<int>(values_.size());
        values_.push_back(val);
        return true;
    }

    [[nodiscard]] auto remove(int val) -> bool {
        auto it = indices_.find(val);
        if (it == indices_.end()) {
            return false;
        }
        const int idx = it->second;
        if (idx != static_cast<int>(values_.size()) - 1) {
            std::swap(values_[idx], values_.back());
            indices_[values_[idx]] = idx;
        }
        indices_.erase(it);
        values_.pop_back();
        return true;
    }

    [[nodiscard]] auto getRandom() const -> int {
        static std::mt19937 gen{std::random_device{}()};
        std::uniform_int_distribution<int> dist(0, static_cast<int>(values_.size()) - 1);
        return values_[dist(gen)];
    }

private:
    std::unordered_map<int, int> indices_;
    std::vector<int> values_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
