/**
 * @brief Direct addressing HashMap using integer array
 * @intuition Constraints allow direct array indexing as hash function
 * @approach Use integer array where index maps to value, -1 indicates absence
 * @complexity Time: O(1) for all operations, Space: O(n) where n is key range
 */
class MyHashMap final {
public:
    MyHashMap() {
        data_.fill(-1);
    }

    void put(const int key, const int value) {
        data_[key] = value;
    }

    [[nodiscard]] int get(const int key) const {
        return data_[key];
    }

    void remove(const int key) {
        data_[key] = -1;
    }

private:
    std::array<int, 1000001> data_{};
};
