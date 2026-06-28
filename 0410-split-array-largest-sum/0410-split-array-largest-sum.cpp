class Solution {
public:

    bool isValid(vector<int>& nums, int k, int maxAllowedSum) {
        int subarrays = 1;
        int currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxAllowedSum) {
                currSum += num;
            } else {
                subarrays++;
                currSum = num;

                if (subarrays > k) {
                    return false;
                }
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int st = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = end;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};