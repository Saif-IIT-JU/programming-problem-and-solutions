class Solution {
    public int[][] generateMatrix(int n) {
        int ans[][] = new int[n][n];
        int m = (n+1)/2, i, j, layer;
        
        int cnt = 1;
        for(layer = 0; layer<m; layer++)
        {
            for(i=layer; i<=n-layer-1; i++)
                ans[layer][i] = cnt++;
            
            for(i=layer+1; i<=n-layer-1; i++)
            {
                ans[i][n-layer-1] = cnt++;
            }
            
            for(i=n-layer-2; i>=layer; i--)
                ans[n-layer-1][i] = cnt++;
            
            for(i=n-layer-2; i>layer; i--)
                ans[i][layer] = cnt++;
        }
        
        return ans;
    }
}
