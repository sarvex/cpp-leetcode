/**
 * @brief Check if four points form a valid square
 * @intuition A square has 4 equal sides and 2 equal diagonals; check all triangles
 * @approach For each triple of points, verify isosceles right triangle property
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool validSquare(const vector<int>& p1, const vector<int>& p2,
                                          const vector<int>& p3, const vector<int>& p4) {
        return isRightIsosceles(p1, p2, p3) && isRightIsosceles(p1, p3, p4) &&
               isRightIsosceles(p1, p2, p4) && isRightIsosceles(p2, p3, p4);
    }

private:
    [[nodiscard]] static bool isRightIsosceles(const vector<int>& a, 
                                                const vector<int>& b, 
                                                const vector<int>& c) {
        const int d1 = distSquared(a, b);
        const int d2 = distSquared(a, c);
        const int d3 = distSquared(b, c);
        
        if (d1 == d2 && d1 + d2 == d3 && d1 > 0) return true;
        if (d1 == d3 && d1 + d3 == d2 && d1 > 0) return true;
        if (d2 == d3 && d2 + d3 == d1 && d2 > 0) return true;
        
        return false;
    }
    
    [[nodiscard]] static int distSquared(const vector<int>& a, const vector<int>& b) {
        const int dx = a[0] - b[0];
        const int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};
