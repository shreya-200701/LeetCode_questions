

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Edge case: if the array is empty, there is no prefix
        if (strs.empty()) return "";
        
        // Sort the array alphabetically
        std::sort(strs.begin(), strs.end());
        
        // Compare only the first and last string
        std::string first = strs.front();
        std::string last = strs.back();
        std::string result = "";
        
        // Iterate through characters until they mismatch or we run out of bounds
        for (size_t i = 0; i < first.length() && i < last.length(); ++i) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break; // Mismatch found, stop checking
            }
        }
        
        return result;
    }
};
