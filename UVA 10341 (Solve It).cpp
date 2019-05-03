#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
#define vi              vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc6(a,b,c,d,e,f)    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              101
int main()
{

      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    double p,q,r,s,t,u;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        double low=0.0,high=1.0,mid;
        if(((p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u)*(p*exp(0)+q*sin(0)+r*cos(0)+s*tan(0)+u) )>0)
        {
            printf("No solution\n");
            continue;
        }
        while(high-low>0.000000001)
        {
            mid=(low+high)/2;
            double eqn=p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;

            if(eqn>0)
                low=mid;
            else if(eqn <0)
                high=mid;
            else
                break;

        }


        printf("%.4lf\n",mid);
    }

    return 0;
    }


