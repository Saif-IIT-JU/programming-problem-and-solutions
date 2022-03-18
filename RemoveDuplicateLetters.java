package remove.duplicate.letters;
import java.util.*;

class Solution {
    public String removeDuplicateLetters(String s) {
        
        int cnt[], vis[], n = s.length();
        cnt = new int[26]; vis = new int[26];
        for(int i=0; i<26; i++){
            cnt[i] = vis[i] = 0;
        }
        StringBuffer ans = new StringBuffer("");
        
        for(int i=0; i<n; i++)
        {
            int c = s.charAt(i) - 'a'; cnt[c]++;
        }
        
        for(int i=0; i<n; i++)
        {
            int c = s.charAt(i) - 'a';
            cnt[c]--;
            if(vis[c]==1) continue;
            
            while(ans.length()>0 && ans.charAt(ans.length()-1)>s.charAt(i)
                 && cnt[ans.charAt(ans.length()-1)-'a']>0)
            {
                vis[ans.charAt(ans.length()-1)-'a'] = 0;
                ans.deleteCharAt(ans.length()-1);
            }
            
            //System.out.println(c+'a');
            ans.append((char)(c+'a')); vis[c] = 1;
        }
        
        return new String(ans);
        
    }
}

public class RemoveDuplicateLetters
{
    public static void main(String[] args)
    {
        Solution sol = new Solution();
        String s = "eofhwoefhwofg";
        System.out.println(sol.removeDuplicateLetters(s));
    }
}