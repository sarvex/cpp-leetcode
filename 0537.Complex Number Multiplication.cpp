/**
 * @brief Multiply two complex numbers in string format
 * @intuition Parse real and imaginary parts, apply (a+bi)(c+di) = (ac-bd)+(ad+bc)i
 * @approach Use sscanf to extract integers from "a+bi" format.
 *           Compute real part (a1*a2 - b1*b2) and imaginary part (a1*b2 + a2*b1).
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto complexNumberMultiply(const string& num1, 
                                                     const string& num2) -> string {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
