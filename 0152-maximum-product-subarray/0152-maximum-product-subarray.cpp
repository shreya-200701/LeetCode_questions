class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

    // Initialize the overall maximum with the first element
    int max_so_far = nums[0];
    
    // Tracks the max and min products ending at the current position
    int current_max = nums[0];
    int current_min = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int num = nums[i];

        // If the current number is negative, swapping max and min 
        // ensures that multiplying by a negative yields the correct bounds
        if (num < 0) {
            std::swap(current_max, current_min);
        }

        // The choices are: start a new subarray at 'num', 
        // or extend the existing subarray
        current_max = std::max(num, current_max * num);
        current_min = std::min(num, current_min * num);

        // Update the global maximum product found so far
        max_so_far = std::max(max_so_far, current_max);
    }

    return max_so_far;
    }
};