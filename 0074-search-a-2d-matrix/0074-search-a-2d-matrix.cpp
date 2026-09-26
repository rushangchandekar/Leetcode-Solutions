class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n-1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(target == mat[row][mid]) {
                return true;
            } else if(target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        // BS on tot rows
        int startRow = 0, endRow = m-1;
        while(startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if(target >= mat[midRow][0] && target <= mat[midRow][n-1]) {
                //found the row => BS on this row
                return searchInRow(mat, target, midRow);
            } else if(target >= mat[midRow][n-1]) {
                //downward => right
                startRow = midRow + 1;
            } else {
                //upward => left
                endRow = midRow - 1;
            }
        }

        return false;
    }
};