/**
 * @brief Data structure for add/find two sum operations
 * @intuition Use hash map to count numbers, find checks for complement existence
 * @approach For find, iterate through map checking if complement exists (handle x==y case)
 * @complexity Time: O(1) add, O(n) find, Space: O(n)
 */

#include <unordered_map>

using std::unordered_map;

class TwoSum final {
private:
    unordered_map<int, int> counts_;
    
public:
    TwoSum() = default;
    
    auto add(int number) -> void {
        ++counts_[number];
    }
    
    [[nodiscard]] auto find(int value) -> bool {
        for (const auto& [num, count] : counts_) {
            const long long complement = static_cast<long long>(value) - num;
            
            if (counts_.count(static_cast<int>(complement)) > 0) {
                if (num != complement || count > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
