class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find total sum
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // Step 2: Check each index
        int leftSum = 0;

        for (int i = 0; i < n; i++) {

            // Right sum = Total sum - Left sum - Current element
            int rightSum = totalSum - leftSum - nums[i];

            // Check if current index is pivot
            if (leftSum == rightSum) {
                return i;
            }

            // Add current element to left sum
            leftSum += nums[i];
        }

        // No pivot index found
        return -1;
    }
};