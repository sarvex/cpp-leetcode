/**
 * @brief Find smallest integer whose digits multiply to given number
 * @intuition Greedily extract largest possible digits (9 to 2) from number
 * @approach Factor out digits from 9 down to 2, build result from smallest digit place
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        
        long long ans = 0;
        long long mul = 1;
        for (int i = 9; i >= 2; --i) {
            while (num % i == 0) {
                num /= i;
                ans = mul * i + ans;
                mul *= 10;
            }
        }
        
        return num < 2 && ans <= INT_MAX ? static_cast<int>(ans) : 0;
    }
};
