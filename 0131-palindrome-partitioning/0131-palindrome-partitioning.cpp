class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string s, int idx, vector<string>& path,
               vector<vector<string>>& ans) {

        // All characters used
        if (idx == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++) {

            // Check current substring
            if (isPalindrome(s, idx, i)) {

                path.push_back(s.substr(idx, i - idx + 1));

                solve(s, i + 1, path, ans);

                path.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(s, 0, path, ans);

        return ans;
    }
};