/**
 * @brief Apply quadratic function and return sorted result
 * @intuition Quadratic function is parabola, extremes are at sorted array ends
 * @approach Two pointers from ends, fill result based on coefficient sign
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> sortTransformedArray(const std::vector<int>& nums, 
                                                                const int a, const int b, const int c) {
        const int n = static_cast<int>(nums.size());
        int i = 0;
        int j = n - 1;
        int k = a < 0 ? 0 : n - 1;
        std::vector<int> result(n);
        
        while (i <= j) {
            const int v1 = transform(a, b, c, nums[i]);
            const int v2 = transform(a, b, c, nums[j]);
            
            if (a < 0) {
                if (v1 <= v2) {
                    result[k++] = v1;
                    ++i;
                } else {
                    result[k++] = v2;
                    --j;
                }
            } else {
                if (v1 >= v2) {
                    result[k--] = v1;
                    ++i;
                } else {
                    result[k--] = v2;
                    --j;
                }
            }
        }
        return result;
    }

private:
    [[nodiscard]] static constexpr int transform(const int a, const int b, const int c, const int x) {
        return a * x * x + b * x + c;
    }
};
