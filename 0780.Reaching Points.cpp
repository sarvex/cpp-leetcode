/**
 * @brief Check if (sx,sy) can reach (tx,ty) via (x+y,y) or (x,x+y)
 * @intuition Work backwards: reduce larger coordinate using modulo
 * @approach Reverse operations until reaching start or impossible state
 * @complexity Time: O(log(max(tx,ty))), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool reachingPoints(const int sx, const int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        
        if (tx == sx && ty == sy) return true;
        if (tx == sx) return ty > sy && (ty - sy) % tx == 0;
        if (ty == sy) return tx > sx && (tx - sx) % ty == 0;
        return false;
    }
};
