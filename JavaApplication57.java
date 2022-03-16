package javaapplication57;
import java.util.*;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer>stk = new Stack<Integer>();
        int n = pushed.length;
        for(int i=0, j=0; i<n; )
        {
            if(stk.isEmpty() || stk.peek()!=popped[i])
            {
                if(j>=n) return false;
                stk.push(pushed[j]); j++;
            }
            else{
                stk.pop(); i++;
            }
        }
        
        return stk.isEmpty();
    }
}

public class JavaApplication57
{
    public static void main(String[] args)
    {
        int pushed[] = {1,2,3,4,5}; int popped[] = {4,5,3,2,1};
        Solution sol = new Solution();
        System.out.println(sol.validateStackSequences(pushed, popped));
    }
}