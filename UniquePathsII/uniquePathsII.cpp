class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(n==0) return 0;
        vector<vector<int> > f(m, vector<int>(n,0));
        if(obstacleGrid[m-1][n-1]) return 0;
        f[m-1][n-1]=1;
        for(int i=m-2;i>=0;i--) {
            if(obstacleGrid[i][n-1]) break;
            f[i][n-1]=f[i+1][n-1];
        }
        for(int j=n-2;j>=0;j--) {
            if(obstacleGrid[m-1][j]) break;
            f[m-1][j]=f[m-1][j+1];
        }
        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                if(obstacleGrid[i][j]) f[i][j]=0;
                else f[i][j]=f[i+1][j]+f[i][j+1];
            }
        }
        return f[0][0];
    }
};
