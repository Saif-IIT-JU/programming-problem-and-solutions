package pkg774c;

import java.util.*;

public class Main
{
    static Scanner sc = new Scanner(System.in); static int min(int x, int y){return Math.min(x, y);}
    static int TEN(int x){if(x==0) return 1; return 10*TEN(x-1);} static int INF = TEN(9)+9;
    static int max(int x, int y){return Math.max(x, y);} static int abs(int x){return Math.abs(x);}
    static boolean Check(int N, int pos){ int x = (N&(1<<pos)); if(x>0) return true; return false;}
    static int Set(int N, int pos){return N|(1<<pos);} static int Toggle(int N, int pos){return N^(1<<pos);}
    static int Off(int N, int pos){if(Check(N,pos)==false) return N; return Toggle(N,pos);}
    static int in(){int a = sc.nextInt(); return a;} static void println(int n){System.out.println(n);}
    static void print(int n){System.out.print(n);} static void print(char c){System.out.print(c);}
    static void print(int arr[]){for(int a: arr) System.out.print(a + " "); System.out.println();}
    
    
    static void Solve()
    {
        int i, j, k, l, m, n, x, y, w, p, q, t;
        System.out.println(max(10,23));
    }
    
    public static void main(String []args)
    {
        int tc = sc.nextInt();
        while(tc-->0)
        {
            Solve();
        }
    }
}