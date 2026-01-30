/**
 * @brief Hash map aggregation for subdomain visit counts
 * @intuition Each domain visit also counts for all parent domains
 * @approach Parse each entry to extract count and domain. For each domain,
 *           add counts to itself and all parent subdomains. Use hash map
 *           to aggregate counts.
 * @complexity Time: O(n * d) where d is max domain depth, Space: O(n * d)
 */
class Solution final {
public:
    [[nodiscard]] static auto subdomainVisits(
        const std::vector<std::string>& cpdomains) -> std::vector<std::string> {
        std::unordered_map<std::string, int> cnt;
        
        for (const auto& s : cpdomains) {
            const auto i = s.find(' ');
            const int v = std::stoi(s.substr(0, i));
            
            for (std::size_t j = i; j < s.size(); ++j) {
                if (s[j] == ' ' || s[j] == '.') {
                    cnt[s.substr(j + 1)] += v;
                }
            }
        }
        
        std::vector<std::string> ans;
        ans.reserve(cnt.size());
        for (const auto& [domain, visits] : cnt) {
            ans.push_back(std::to_string(visits) + " " + domain);
        }
        return ans;
    }
};
