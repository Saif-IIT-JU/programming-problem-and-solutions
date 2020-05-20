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
#define			INF 			1e9
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

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};    // King's move
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hx[]={-2,-2,-1,+1,+2,+2,-1,+1};    // Knight's move
int hy[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

string mov, leaf; int n;
vector<int>order;
map<int,char>Map;

char go(int root)
{
    for(int i=0; i<n; i++)
    {
        int lvl = order[i];
        if(mov[lvl-1]=='0') root = root*2;
        else                root = root*2+1;
    }

    return Map[root];
}

int main()
{
/*	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);  */

    int i,j,k,l,m,p,q,x,y,u,v,r,tc,t;

    tc = 0;
    while(true)
    {
        cin>>n; if(n==0) break;

        for(i=0; i<n; i++)
        {
            string s; cin>>s;
            order.push_back(s[1]-'0');
        }

        cin>>leaf;  p  = 1<<n;

        for(i=0; i<leaf.size(); i++)
        {
            Map[i+p] = leaf[i];
        }

        cin>>m; string ans = "";

        for(i=0; i<m; i++)
        {
            cin>>mov;
            char c = go(1);
            ans+=c;
        }

        cout<<"S-Tree #"<<++tc<<":\n";
        cout<<ans<<endl<<endl;

        order.clear(); Map.clear();
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
