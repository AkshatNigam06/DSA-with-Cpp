class Solution {
public:

    int binary(vector<int>& nums, int target, int start, int end) {

        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            return binary(nums, target, mid + 1, end);

        else
            return binary(nums, target, start, mid - 1);
    }

    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size() - 1);
    }
};