package javaapplication54;

class Solution {
    int dp[], num[], vis[], n;
    
    int solve(int i)
    {
        //System.out.println(i);
        if(num[i]==0) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        vis[i] = 1;
        
        int ret = 0;
        if(i+num[i]<n && vis[i+num[i]]==0 && solve(i+num[i])==1) ret = 1;
        if(i-num[i]>=0 && vis[i-num[i]]==0 && solve(i-num[i])==1) ret = 1;
        
        
        return dp[i] = ret;
    }
    
    public boolean canReach(int[] arr, int start) {
        n = arr.length; dp = new int[n]; num = new int[n]; vis = new int[n];
        for(int i=0; i<n; i++){
            num[i] = arr[i]; dp[i] = -1; vis[i] = 0;
        }
        
        return solve(start)==1;
    }
}

public class JavaApplication54
{
    public static void main(String [] args)
    {
        int arr[] = {1,2,3,4,54,0,5,6,6,7,7,0,4,5,6,0,0,4,5,7}; int start = 3;
        
        Solution s = new Solution();
        System.out.println(s.canReach(arr, start));
    }
}