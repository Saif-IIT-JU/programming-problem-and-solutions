package pkg776c;

import java.util.*;

public class Main
{
    static class Info implements Comparable<Info>
    {
        int pos, wt, idx;
    
        Info(){}
        Info(int pos, int wt, int idx)
        {
            this.pos = pos; this.wt = wt; this.idx = idx;
        }
    
        public int compareTo(Info obj)
        {
            return wt-obj.wt;
        }
    }

    static class Info2 implements Comparable<Info2>
    {
        int pos, idx;
    
        Info2(){}
        Info2(int pos, int idx)
        {
            this.pos = pos; this.idx = idx;
        }
    
        public int compareTo(Info2 obj)
        {
            return pos-obj.pos;
        }
    
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(), i, j, k, l, m, n, tot, x, w;
        
        while(tc-->0)
        {
            ArrayList<Info>al = new ArrayList<Info>();
            
            n = sc.nextInt(); m = sc.nextInt();
            
            for(i=0; i<m; i++)
            {
                x = sc.nextInt(); w = sc.nextInt();
                al.add(new Info(x, w, i));
            }
            
            Collections.sort(al);
            ArrayList<Info2>ans = new ArrayList<Info2>();
            
            tot = 0;
            for(i=0; i<2*n; i++)
            {
                tot+=al.get(i).wt;
                ans.add(new Info2(al.get(i).pos, al.get(i).idx));
            }
            
            System.out.println(tot);
            Collections.sort(ans);
            for(i=0; i<n; i++)
            {
                //System.out.println(i + " " + (2*n-i-1));
                System.out.println(ans.get(i).idx+1 + " " + (ans.get(2*n-i-1).idx+1));
            }
        }
    }
}