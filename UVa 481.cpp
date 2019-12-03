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

    n = 0; vector<int>ara;

   // tc = 8;
    while(scanf("%d", &v)!=EOF)
    {
        ara.push_back(v); n++;
    }

    int P[n+9], id[n+9];
    vector<int>lis;
    q = 0;
    for(i=0; i<n; i++)
    {
        int lb = lower_bound(lis.begin(), lis.end(), ara[i]) - lis.begin();

        id[lb] = i;
        if(lb==0) P[i] = -1;
        else      P[i] = id[lb-1];

        if(lb>=lis.size())
        {
            q = i;
            lis.push_back(ara[i]);
        }
        else
            lis[lb] = ara[i];

        if(lb==lis.size()-1)
            q = i;
    }

    printf("%d\n-\n", lis.size());

    x = q; lis.clear();
    while(x>=0)
    {
        lis.push_back(ara[x]);
        x = P[x];
    }

    reverse(lis.begin(), lis.end());

    for(i=0; i<lis.size(); i++)
    {
        printf("%d\n", lis[i]);
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
