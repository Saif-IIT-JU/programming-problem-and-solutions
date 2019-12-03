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

    //tc = in();
    scanf("%d", &tc);
    getchar();
    getchar();

    while(tc--)
    {
        vector<int>v1; //m = 5;
        string s;
        while(getline(cin,s))
        {
            if(s[0]=='\0') break;
            stringstream sso;
            sso<<s;
            sso>>v;
            v1.push_back(v);
        }

        n = v1.size(); //cout<<n<<endl;
        int id[n+9], P[n+9];
        vector<int>lis;

        for(i=0; i<n; i++)
        {
            x = v1[i];
            int lb = lower_bound(lis.begin(), lis.end(), x) - lis.begin();

            id[lb] = i;

            if(lb>=lis.size())
            {
                lis.push_back(x);
                q = i;
            }
            else lis[lb] = x;

            if(lb==0) P[i] = -1;
            else      P[i] = id[lb-1];
        }

        printf("Max hits: %d\n", (int)lis.size());

        vector<int>ans;

        //for(i=0; i<n; i++)
          //  cout<<P[i]<< " ";  cout<<endl;

        while(q>=0)
        {
            ans.push_back(v1[q]);
            q = P[q];
        }
        reverse(ans.begin(), ans.end());

        for(i=0; i<ans.size(); i++)
            printf("%d\n", ans[i]);

        if(tc) printf("\n");
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
