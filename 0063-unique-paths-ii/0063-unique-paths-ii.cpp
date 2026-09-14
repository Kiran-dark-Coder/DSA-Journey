// class Solution {
// public:
//     int solve(int i,int j,vector<vector<int>>& obstacleGrid){
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
        
//         if(i==m-1 && j==n-1){
//             return 1;

//         }
//         if(i>=m || j>=n) return 0;
//         if(obstacleGrid[i][j]==1) return 0;
//         return solve(i+1,j,obstacleGrid) + solve(i,j+1,obstacleGrid);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         return solve(0,0,obstacleGrid);
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<vector<int>> path(m, vector<int>(n, 0));

        path[0][0] = 1;

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && path[i - 1][0] == 1) {
                path[i][0] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0 && path[0][i - 1] == 1) {
                path[0][i] = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        }

        return path[m - 1][n - 1];
    }
};