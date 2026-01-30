/**
 * @brief Trace path from label to root in a zigzag-labeled binary tree
 * @intuition Account for the zigzag labeling when computing parent positions
 * @approach Find the level of the label, then trace back to root. At each level,
 *           compute the mirrored position due to zigzag ordering before finding parent.
 * @complexity Time: O(log n), Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> pathInZigZagTree(int label) {
        int x = 1, i = 1;
        while ((x << 1) <= label) {
            x <<= 1;
            ++i;
        }
        vector<int> ans;
        for (; i > 0; --i) {
            ans.push_back(label);
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1;
        }
        ranges::reverse(ans);
        return ans;
    }
};
