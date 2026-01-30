/**
 * @brief Add two integers using bit manipulation without + or -
 * @intuition XOR gives sum without carry, AND shifted left gives carry
 * @approach Iterate: XOR for partial sum, AND+shift for carry, until no carry
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto getSum(int a, int b) -> int {
        while (b != 0) {
            const auto carry = static_cast<unsigned int>(a & b) << 1;
            a = a ^ b;
            b = static_cast<int>(carry);
        }
        return a;
    }
};
