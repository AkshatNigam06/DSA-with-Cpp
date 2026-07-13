class Solution {
public:
    void solve(vector<int>& candidates, int target,
               int idx,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // Found answer
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        // Invalid case
        if (target < 0 || idx == candidates.size())
            return;

        // Take current number
        path.push_back(candidates[idx]);

        // Stay on same index because we can reuse it
        solve(candidates, target - candidates[idx],
              idx, path, ans);

        path.pop_back();

        // Skip current number
        solve(candidates, target,
              idx + 1, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(candidates, target, 0, path, ans);

        return ans;
    }
};