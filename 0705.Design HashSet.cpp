/**
 * @brief Direct addressing HashSet using boolean array
 * @intuition Constraints allow direct array indexing as hash function
 * @approach Use boolean array where index represents key presence
 * @complexity Time: O(1) for all operations, Space: O(n) where n is key range
 */
class MyHashSet final {
public:
    MyHashSet() {
        data_.fill(false);
    }

    void add(const int key) {
        data_[key] = true;
    }

    void remove(const int key) {
        data_[key] = false;
    }

    [[nodiscard]] bool contains(const int key) const {
        return data_[key];
    }

private:
    std::array<bool, 1000001> data_{};
};
