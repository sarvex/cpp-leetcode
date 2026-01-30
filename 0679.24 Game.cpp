/**
 * @brief Check if 4 cards can make 24 using +, -, *, /
 * @intuition Try all pairs and operations recursively, reduce to 3, 2, 1 numbers
 * @approach DFS trying all combinations of two numbers and four operations
 * @complexity Time: O(1) - bounded by card count, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool judgePoint24(const vector<int>& cards) {
        vector<double> nums;
        nums.reserve(4);
        for (const int num : cards) {
            nums.push_back(static_cast<double>(num));
        }
        return dfs(nums);
    }

private:
    static constexpr char ops_[] = {'+', '-', '*', '/'};

    [[nodiscard]] static bool dfs(vector<double>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return abs(nums[0] - 24) < 1e-6;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    vector<double> nxt;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            nxt.push_back(nums[k]);
                        }
                    }
                    for (const char op : ops_) {
                        if (op == '/' && nums[j] == 0) {
                            continue;
                        }
                        switch (op) {
                            case '+': nxt.push_back(nums[i] + nums[j]); break;
                            case '-': nxt.push_back(nums[i] - nums[j]); break;
                            case '*': nxt.push_back(nums[i] * nums[j]); break;
                            case '/': nxt.push_back(nums[i] / nums[j]); break;
                        }
                        if (dfs(nxt)) {
                            return true;
                        }
                        nxt.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
