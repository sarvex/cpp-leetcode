/**
 * @brief Design phone directory with get, check, and release operations
 * @intuition Track available numbers in a set for O(1) operations
 * @approach Use unordered_set to store available phone numbers
 * @complexity Time: O(1) average per operation, Space: O(n)
 */
class PhoneDirectory final {
public:
    explicit PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available_.insert(i);
        }
    }

    [[nodiscard]] auto get() -> int {
        if (available_.empty()) {
            return -1;
        }
        const int x = *available_.begin();
        available_.erase(x);
        return x;
    }

    [[nodiscard]] auto check(int number) const -> bool {
        return available_.contains(number);
    }

    auto release(int number) -> void {
        available_.insert(number);
    }

private:
    std::unordered_set<int> available_;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
