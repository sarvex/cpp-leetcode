/**
 * @brief Parse and evaluate Lisp expressions
 * @intuition Recursive descent parser with scope-based variable binding
 * @approach Parse let/add/mult expressions recursively, manage variable scopes
 * @complexity Time: O(n), Space: O(n) for recursion and scope storage
 */
class Solution final {
public:
    [[nodiscard]] int evaluate(const std::string& expression) {
        expr_ = expression;
        pos_ = 0;
        return eval();
    }

private:
    std::string expr_;
    int pos_ = 0;
    std::unordered_map<std::string, std::vector<int>> scope_;

    [[nodiscard]] int eval() {
        if (expr_[pos_] != '(') {
            return std::islower(expr_[pos_]) ? scope_[parseVar()].back() : parseInt();
        }
        
        ++pos_;
        int result = 0;
        
        if (expr_[pos_] == 'l') {
            pos_ += 4;
            std::vector<std::string> vars;
            while (true) {
                std::string var = parseVar();
                if (expr_[pos_] == ')') {
                    result = scope_[var].back();
                    break;
                }
                ++pos_;
                vars.push_back(var);
                scope_[var].push_back(eval());
                ++pos_;
                if (!std::islower(expr_[pos_])) {
                    result = eval();
                    break;
                }
            }
            for (const auto& v : vars) {
                scope_[v].pop_back();
            }
        } else {
            const bool isAdd = expr_[pos_] == 'a';
            pos_ += isAdd ? 4 : 5;
            const int a = eval();
            ++pos_;
            const int b = eval();
            result = isAdd ? a + b : a * b;
        }
        
        ++pos_;
        return result;
    }

    [[nodiscard]] std::string parseVar() {
        const int start = pos_;
        while (pos_ < static_cast<int>(expr_.size()) && 
               expr_[pos_] != ' ' && expr_[pos_] != ')') {
            ++pos_;
        }
        return expr_.substr(start, pos_ - start);
    }

    [[nodiscard]] int parseInt() {
        int sign = 1;
        int value = 0;
        if (expr_[pos_] == '-') {
            sign = -1;
            ++pos_;
        }
        while (pos_ < static_cast<int>(expr_.size()) && 
               expr_[pos_] >= '0' && expr_[pos_] <= '9') {
            value = value * 10 + (expr_[pos_] - '0');
            ++pos_;
        }
        return sign * value;
    }
};
