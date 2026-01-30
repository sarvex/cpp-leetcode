/**
 * @brief Count good numbers that become different after 180° rotation
 * @intuition Valid digits: 0,1,2,5,6,8,9; must contain at least one of 2,5,6,9
 * @approach Check each number for validity and difference after rotation
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int rotatedDigits(const int n) {
        constexpr std::array<int, 10> rotations{0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        
        auto isGood = [&](int x) -> bool {
            int rotated = 0;
            int multiplier = 1;
            const int original = x;
            
            while (x) {
                const int digit = x % 10;
                if (rotations[digit] == -1) {
                    return false;
                }
                rotated = rotations[digit] * multiplier + rotated;
                multiplier *= 10;
                x /= 10;
            }
            return original != rotated;
        };
        
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            count += isGood(i);
        }
        return count;
    }
};
