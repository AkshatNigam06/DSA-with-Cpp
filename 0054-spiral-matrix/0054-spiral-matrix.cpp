class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int sRow = 0;
        int eRow = row - 1;
        int sCol = 0;
        int eCol = col - 1;

        while (sRow <= eRow && sCol <= eCol) {

            // Left -> Right
            for (int i = sCol; i <= eCol; i++) {
                ans.push_back(matrix[sRow][i]);
            }
            sRow++;

            // Top -> Bottom
            for (int i = sRow; i <= eRow; i++) {
                ans.push_back(matrix[i][eCol]);
            }
            eCol--;

            // Right -> Left
            if (sRow <= eRow) {
                for (int i = eCol; i >= sCol; i--) {
                    ans.push_back(matrix[eRow][i]);
                }
                eRow--;
            }

            // Bottom -> Top
            if (sCol <= eCol) {
                for (int i = eRow; i >= sRow; i--) {
                    ans.push_back(matrix[i][sCol]);
                }
                sCol++;
            }
        }

        return ans;
    }
};