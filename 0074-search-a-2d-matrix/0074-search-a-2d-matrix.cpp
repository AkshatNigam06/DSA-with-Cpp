class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int start = 0;
        int end = matrix[0].size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return searchInRow(matrix, target, mid);
            }
            else if (target > matrix[mid][n - 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }
};