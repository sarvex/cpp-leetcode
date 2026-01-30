/**
 * @brief Greedy grouping of consecutive cards
 * @intuition Sort cards, greedily form groups starting from smallest available
 * @approach Sort hand, count each card. For each card, if available, try to
 *           form a group of consecutive cards. Fail if any card in group missing.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto isNStraightHand(std::vector<int>& hand,
                                               int groupSize) -> bool {
        if (hand.size() % groupSize != 0) return false;
        
        std::ranges::sort(hand);
        std::unordered_map<int, int> cnt;
        for (const int x : hand) {
            ++cnt[x];
        }
        
        for (const int x : hand) {
            if (cnt.contains(x)) {
                for (int y = x; y < x + groupSize; ++y) {
                    if (!cnt.contains(y)) {
                        return false;
                    }
                    if (--cnt[y] == 0) {
                        cnt.erase(y);
                    }
                }
            }
        }
        return true;
    }
};
