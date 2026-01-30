/**
 * @brief Validate XML-like code with tags and CDATA sections
 * @intuition Use stack to match opening/closing tags; handle CDATA specially
 * @approach Parse sequentially: detect CDATA, closing tags, opening tags; validate nesting
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool isValid(const string& code) {
        stack<string> tagStack;
        
        for (size_t i = 0; i < code.size(); ++i) {
            if (i > 0 && tagStack.empty()) {
                return false;
            }
            
            if (code.substr(i, 9) == "<![CDATA[") {
                const auto end = code.find("]]>", i + 9);
                if (end == string::npos) {
                    return false;
                }
                i = end + 2;
            } else if (code.substr(i, 2) == "</") {
                const auto end = code.find('>', i + 2);
                if (end == string::npos) {
                    return false;
                }
                const string tag = code.substr(i + 2, end - i - 2);
                if (!isValidTag(tag) || tagStack.empty() || tagStack.top() != tag) {
                    return false;
                }
                tagStack.pop();
                i = end;
            } else if (code[i] == '<') {
                const auto end = code.find('>', i + 1);
                if (end == string::npos) {
                    return false;
                }
                const string tag = code.substr(i + 1, end - i - 1);
                if (!isValidTag(tag)) {
                    return false;
                }
                tagStack.push(tag);
                i = end;
            }
        }
        
        return tagStack.empty();
    }

private:
    [[nodiscard]] static bool isValidTag(const string& tag) {
        const int n = static_cast<int>(tag.size());
        if (n < 1 || n > 9) {
            return false;
        }
        for (const char c : tag) {
            if (!isupper(c)) {
                return false;
            }
        }
        return true;
    }
};
