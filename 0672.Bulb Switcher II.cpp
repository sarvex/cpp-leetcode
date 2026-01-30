/**
 * @brief Count distinct bulb states after exactly m presses
 * @intuition Only first 6 bulbs matter due to periodicity; enumerate all button combos
 * @approach Try all 16 button combinations matching presses parity, count unique states
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int flipLights(int n, const int presses) {
        n = min(n, 6);
        const vector<int> ops = {0b111111, 0b010101, 0b101010, 0b100100};
        unordered_set<int> vis;
        
        for (int mask = 0; mask < (1 << 4); ++mask) {
            const int cnt = __builtin_popcount(mask);
            if (cnt > presses || cnt % 2 != presses % 2) {
                continue;
            }
            
            int t = 0;
            for (int i = 0; i < 4; ++i) {
                if (mask >> i & 1) {
                    t ^= ops[i];
                }
            }
            t &= (1 << 6) - 1;
            t >>= (6 - n);
            vis.insert(t);
        }
        return vis.size();
    }
};
