/**
 * @brief Mathematical analysis using GCD to find receptor
 * @intuition Light bounces until reaching receptor; use LCM to find meeting point
 * @approach Reduce p/q to lowest terms using GCD. The receptor hit depends on
 *           parity: if p odd and q odd -> 1, p odd and q even -> 0, p even -> 2.
 * @complexity Time: O(log(min(p,q))), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto mirrorReflection(int p, int q) -> int {
        const int g = std::gcd(p, q);
        p = (p / g) % 2;
        q = (q / g) % 2;
        
        if (p == 1 && q == 1) return 1;
        return p == 1 ? 0 : 2;
    }
};
