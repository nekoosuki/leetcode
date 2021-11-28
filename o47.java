class Solution {
    public int maxValue(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        for(int i=m-2;i>=0;i--){
            grid[i][n-1] += grid[i+1][n-1];
        }
        for(int i=n-2;i>=0;i--){
            grid[m-1][i] += grid[m-1][i+1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                grid[i][j] += Math.max(grid[i][j+1],grid[i+1][j]);
            }
        }
        return grid[0][0];
    }
}