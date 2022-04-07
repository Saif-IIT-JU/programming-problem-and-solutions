package leetcode1046;
import java.util.*;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        int n = stones.length;
        for(int i=0; i<n; i++)
        {
            pq.add(-stones[i]);
        }
        
        while(pq.size()>1)
        {
            int x = -pq.peek(); pq.poll();
            int y = -pq.peek(); pq.poll();
            if(x>y){
                pq.add(y-x);
            }
        }
        
        if(pq.size()==0) return 0;
        else return -pq.peek();
    }
}

public class LeetCode1046 {

    public static void main(String[] args) {
       Solution sol = new Solution();
       int stones[] = {1, 2, 3, 1, 4, 5, 1, 2, 5, 3};
       
       System.out.println(sol.lastStoneWeight(stones));
    }
    
}
