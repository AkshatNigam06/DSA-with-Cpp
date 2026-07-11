class Solution {
public:

    void solve(vector<int>& nums, int idx,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Base Case
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, ans);

        // Backtrack
        temp.pop_back();

        // Exclude
        solve(nums, idx + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);

        return ans;
    }
};