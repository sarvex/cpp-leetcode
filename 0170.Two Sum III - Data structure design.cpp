/**
 * @brief Data structure for add/find two sum operations
 * @intuition Use hash map to count numbers, find checks for complement existence
 * @approach For find, iterate through map checking if complement exists (handle x==y case)
 * @complexity Time: O(1) add, O(n) find, Space: O(n)
 */

class TwoSum final {
private:
    std::unordered_map<int, int> counts_;
    
public:
    TwoSum() = default;
    
    auto add(int number) -> void {
        ++counts_[number];
    }
    
    [[nodiscard]] auto find(int value) const -> bool {
        for (const auto& [num, count] : counts_) {
            const auto complement = static_cast<long long>(value) - num;
            
            if (counts_.contains(static_cast<int>(complement))) {
                if (num != complement || count > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
