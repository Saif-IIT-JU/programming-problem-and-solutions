package score.of.parentheses;
import java.util.*;

class pair
{
    int idx, score;
    pair(){}
    pair(int idx, int score)
    {
        this.idx = idx; this.score = score;
    }
}

class Solution {
    public int scoreOfParentheses(String s) {
        int n = s.length(), i;
        Stack<Integer>stk = new Stack<Integer>();
        Stack<pair>scores = new Stack<pair>();
        
        for(i=0; i<n; i++)
        {
            char c = s.charAt(i);
            
            if(c=='('){
                stk.push(i);
            }
            else{
                int tp = stk.peek(); stk.pop(); int sum = 0;
                while(!scores.isEmpty() && scores.peek().idx>tp)
                {
                    sum+=scores.peek().score; scores.pop();
                }
                if(sum==0) sum = 1;
                else sum*=2;
                scores.push(new pair(tp, sum));
            }
        }
        
        int ans = 0;
        while(!scores.isEmpty()){
            ans+=scores.peek().score; scores.pop();
        }
        
        return ans;
    }
}
public class ScoreOfParentheses {

    public static void main(String[] args) {
        String s = "((()()())(()()()))((()()())(()()()))";
        Solution sol = new Solution();
        
        System.out.println(sol.scoreOfParentheses(s));
    }
    
}
