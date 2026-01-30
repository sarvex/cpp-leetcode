/**
 * @brief Parse string into NestedInteger (either integer or list of NestedIntegers)
 * @intuition Recursive structure: either a number or [elements separated by commas]
 * @approach Parse recursively, track depth to find comma separators at current level
 * @complexity Time: O(n^2) worst case, Space: O(n) recursion depth
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution final {
public:
    [[nodiscard]] static auto deserialize(const std::string& s) -> NestedInteger {
        if (s.empty() || s == "[]") {
            return NestedInteger();
        }

        if (s[0] != '[') {
            return NestedInteger(std::stoi(s));
        }

        NestedInteger ans;
        int depth = 0;
        const auto n = static_cast<int>(s.size());

        for (int i = 1, j = 1; i < n; ++i) {
            if (depth == 0 && (s[i] == ',' || i == n - 1)) {
                ans.add(deserialize(s.substr(j, i - j)));
                j = i + 1;
            } else if (s[i] == '[') {
                ++depth;
            } else if (s[i] == ']') {
                --depth;
            }
        }

        return ans;
    }
};
