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
#define         EPS             1e-9
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

const int MAXN = (int)2e5+9;

struct point
{
    double x, y;
    point(){}
    point(double xx, double yy)
    {
        x = xx; y = yy;
    }

    bool operator<(const point &b)const
    {
        if(fabs(x-b.x)<EPS)
        {
            return y < b.y;
        }
        else  return  x < b.x;
    }
    bool operator==(const point &b)const
    {
        if(fabs(x-b.x)<EPS && fabs(y-b.y)<EPS) return true;
        else  return false;
    }
};

double dist(point p1, point p2)
{
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

point Rotate(point p, double ang)
{
    ang = ang*PI/180.0; point ret;
    ret.x = p.x*cos(ang) - p.y*sin(ang);
    ret.y = p.x*sin(ang) + p.y*cos(ang);

    return ret;
}

struct line         // defination of line ax + by + c = 0 (where b = 1).
{
    double a, b, c;
    line(){}
    line(double aa, double bb, double cc)
    {
        a = aa; b = bb; c = cc;
    }
};

void pointsToLine(point p1, point p2, line &l)
{
    if(p1.x==p2.x){
        l.a = 1, l.b = 0, l.c = -p1.x;
    }else{
        l.a = -(double)(p1.y - p2.y)/(p1.x-p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a*p1.x)-p1.y;
    }

    return ;
}

bool areParallel(line l1, line l2)
{
    if(fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS) return true;
    return false;
}

bool areSame(line l1, line l2)
{
    if(areParallel(l1, l2) && fabs(l1.c-l2.c)<EPS) return true;
    return false;
}

bool areIntersect(line l1, line l2, point &p)
{
    if(areParallel(l1, l2)) return false;
    else{
        p.x = (l1.b*l2.c - l2.b*l1.c)/(l1.a*l2.b - l2.a*l1.b);
        p.y = (l2.a*l1.c - l1.a*l2.c)/(l1.a*l2.b - l2.a*l1.b);
        return true;
    }
}

struct vec
{
    double x, y;
    vec(){}
    vec(double xx, double yy) : x(xx), y(yy){}
};

vec toVec(point p1, point p2)
{
    return vec(p2.x-p1.x, p2.y-p1.y);
}

vec scale(vec v, double s)
{
    return vec(v.x*s, v.y*s);
}

point translate(point p, vec v)
{
    return point(p.x+v.x, p.y+v.y);
}

double norm_sq(vec v)
{
    return v.x*v.x + v.y*v.y;
}

double dot(vec a, vec b)
{
    return a.x*b.x + a.y*b.y;
}

double cross(vec a, vec b)
{
    return a.x*b.y - a.y*b.x;
}

double angle(point a, point o, point b)
{
    vec oa = toVec(o,a);
    vec ob = toVec(o,b);
    return acos(dot(oa,ob)/(sqrt(norm_sq(oa))*sqrt(norm_sq(ob))));
}

double angle(vec oa, vec ob)
{
    return acos(dot(oa,ob)/(sqrt(norm_sq(oa))*sqrt(norm_sq(ob))));
}

bool ccw(point p, point q, point r)
{
    return cross(toVec(p,q), toVec(p,r)) > 0.0;
}

bool coLinear(point p, point q, point r)
{
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

bool lineSegmentIntersect(point p1, point p2, point p3, point p4)
{
    if(ccw(p1,p2,p3)!=ccw(p1,p2,p4) && ccw(p3,p4,p1)!=ccw(p3,p4,p2)) return true;
    else  return false;
}

void pointSlopeToLine(point p, double m, line &l)
{
    l.a = -m;
    l.b = 1;
    l.c = m*p.x - p.y;

    return ;
}

void closestPoint(line l, point p, point &ans)
{
    if(fabs(l.b)<EPS){
        ans.x = -(l.c); ans.y = p.y; return ;
    }else if(fabs(l.a)<EPS){
        ans.x = p.x; ans.y = -(l.c); return ;
    }else{
        line perpendicluar;
        pointSlopeToLine(p, 1/l.a, perpendicluar);
        areIntersect(l, perpendicluar, ans);
        return ;
    }
}

double distToLine(point p, point a, point b, point &c)
{
    line l;
    pointsToLine(a, b, l);
    closestPoint(l, p, c);
    return dist(p,c);
}

double distToLine(point p, point a, point b)
{
    vec ab = toVec(a,b);
    vec ap = toVec(a,p);
    return fabs(cross(ab,ap))/sqrt(norm_sq(ab));
}

double distToLineSegment(point p, point a, point b)
{
    if(dot(toVec(a,b),toVec(b,p))>0) return dist(p,b);
    if(dot(toVec(b,a),toVec(a,p))>0) return dist(p,a);
    return distToLine(p,a,b);
}

struct point_i
{
    int x, y, z;
    point_i(){}
    point_i(int xx, int yy, int zz) : x(xx), y(yy), z(zz){}

    bool operator<(const point_i &p)const
    {
        vec v1 = toVec(point(0,0),point(x,y));
        vec v2 = toVec(point(0,0), point(p.x,p.y));
        vec v3 = toVec(point(0,0), point(1000000,0));
        double ang1 = angle(v1,v3);
        double ang2 = angle(v2,v3);

        if(fabs(ang1-ang2)<EPS) return dist(point(0,0),point(x,y)) <
            dist(point(0,0),point(p.x,p.y));
        else return ang1<ang2;
    }
};

bool cmp(point_i a, point_i b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main()
{
/*	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);  */

    int i,j,k,l,m,n,p,q,x,y,u,v,r,tc,t;

    tc = 0; while(true)
    {
        n = in(); if(n==0) break;
        vector<point_i>vv;

        for(i=0; i<n; i++){
            x = in(), y = in(), p = in();
            vv.push_back(point_i(x,y,p));
        }

        sort(vv.begin(), vv.end());

       // for(i=0; i<n; i++) cout<<vv[i].x<<" "<<vv[i].y<<endl;
        vector<point_i>ans;

        for(i=0; i<n; )
        {
            j = i;
            while(j<n && vv[i].y*vv[j].x==vv[i].x*vv[j].y) j++;

           // cout<<"RUN "<<i<<" "<<j<<endl;
            int mx = -1;
            for(k=i; k<j; k++){
                if(vv[k].z<=mx) ans.push_back(vv[k]);
                mx = max(mx, vv[k].z);
            }

            i = j;
        }

        sort(ans.begin(), ans.end(), cmp);

        printf("Data set %d:\n", ++tc);

        m = ans.size();
        if(m==0) printf("All the lights are visible.\n");
        else{
            printf("Some lights are not visible:\n");
            for(i=0; i<m; i++)
            {
                printf("x = %d, y = %d", ans[i].x, ans[i].y);
                if(i==m-1) printf(".\n");
                else       printf(";\n");
            }
        }
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
