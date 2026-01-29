/**
 * @brief Character mapping validation for isomorphism
 * @intuition Two strings are isomorphic if characters map one-to-one
 * @approach Track last seen position for each character in both strings
 * @complexity Time: O(n), Space: O(1) - fixed size arrays
 */

class Solution final {
public:
    [[nodiscard]] static auto isIsomorphic(const std::string& s, const std::string& t) -> bool {
        std::array<int, 256> mapS{};
        std::array<int, 256> mapT{};
        const auto n = s.size();
        
        for (std::size_t i = 0; i < n; ++i) {
            const auto charS = static_cast<unsigned char>(s[i]);
            const auto charT = static_cast<unsigned char>(t[i]);
            if (mapS[charS] != mapT[charT]) {
                return false;
            }
            mapS[charS] = mapT[charT] = static_cast<int>(i + 1);
        }
        
        return true;
    }
};
