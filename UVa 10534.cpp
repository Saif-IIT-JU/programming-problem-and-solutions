/*

    author : s@if

*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define 		NIL 			-1
#define		 	fi	 		    first
#define 		sec 			second
#define 		MAX 			INT_MAX
#define			INF 			99999999
#define 		ll 			    long long
#define 		PI 			    acos(-1.0)
#define			MOD 			1000000007
#define 		PLL 			pair<ll,ll>
#define 		PII			    pair<int,int>
#define 		ull 			unsigned long long
#define 		For(i,a,b) 		for(int i=a;i<=(int)b;i++)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;


inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos)	{	return (bool) (N & (1<<pos));}
int Set(int N, int pos) {	return N = N | (1<<pos);}

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hr[]={-2,-2,-1,+1,+2,+2,-1,+1};
int hc[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

const int MAXN = (int)1e5+9;

int main()
{
/*	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);  */

    int i,j,k,l,m,n,p,q,x,y,u,v,r,tc,t;

    while(scanf("%d", &n)==1)
    {
        int ara[n+9], lis1[n+9], lis2[n+9];

        for(i=0; i<n; i++) ara[i] = in();

        for(i=0; i<=n; i++) lis1[i] = lis2[i] = 1;

        vector<int>lis;

        for(i=0; i<n; i++)
        {
            x = ara[i];
            int lb = lower_bound(lis.begin(), lis.end(), x)-lis.begin();
            if(lb>=lis.size())
                lis.push_back(x);
            else
                lis[lb] = x;

            lis1[i] = lis.size();
        }

        lis.clear();

        for(i=n-1; i>=0; i--)
        {
            x = ara[i];
            int lb = lower_bound(lis.begin(), lis.end(),x)-lis.begin();
            if(lb>=lis.size())
                lis.push_back(x);
            else
                lis[lb] = x;

            lis2[i] = lis.size();
        }

        int ans = 0;

       // for(i=0; i<n; i++)
       //     cout<<lis1[i]<<" "; cout<<endl;
       // for(i=0; i<n; i++)
       //     cout<<lis2[i]<<" "; cout<<endl;

        for(i=0; i<n; i++)
        {
            if(lis1[i]==lis2[i])
                ans = max(ans, 2*lis1[i]-1);
        }

        printf("%d\n", ans);
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
