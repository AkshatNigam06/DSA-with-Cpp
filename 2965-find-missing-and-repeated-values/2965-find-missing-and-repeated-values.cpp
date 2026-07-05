class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        unordered_set<int> s;
        vector<int> ans;

        int n = grid.size();
        int repeated;

        int expectedSum = 0, actualSum = 0;

        // Find repeated number and calculate actual sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                }

                s.insert(grid[i][j]);
            }
        }

        int total = n * n;

        // Expected sum of numbers from 1 to n²
        expectedSum = total * (total + 1) / 2;

        // Missing = ExpectedSum - (ActualSum - Repeated)
        int missing = expectedSum - (actualSum - repeated);

        ans.push_back(repeated);
        ans.push_back(missing);

        return ans;
    }
};