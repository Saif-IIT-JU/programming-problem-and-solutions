package twocityschedule;
import java.util.*;

class Solution {
    int INF = 1000000000, n, dp[][], cost[][];
    
    int solve(int i, int cnt)
    {
        if(i>=n){
            if(cnt==n/2) return 0;
            else return INF;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        
        int ret = INF;
        if(cnt<n/2){
            ret = Math.min(ret, cost[i][0]+solve(i+1, cnt+1));
            ret = Math.min(ret, cost[i][1]+solve(i+1, cnt));
        }
        else ret = Math.min(ret, cost[i][1]+solve(i+1, cnt));
        
        return dp[i][cnt] = ret;
    }
    
    public int twoCitySchedCost(int[][] costs) {
        n = costs.length; dp = new int[n][n]; cost = new int[n][2];
        for(int i=0; i<n; i++)
        {
            cost[i][0] = costs[i][0];
            cost[i][1] = costs[i][1];
            for(int j=0; j<n; j++)
                dp[i][j] = -1;
        }
        
        return solve(0,0);
    }
}

public class TwoCitySchedule {

    public static void main(String[] args) {
        
        Solution sol = new Solution();
        int costs[][] = {{10,20},{30,200},{400,50},{30,20}};
        
        int res = sol.twoCitySchedCost(costs);
        
        System.out.println(res);
    }
    
}
