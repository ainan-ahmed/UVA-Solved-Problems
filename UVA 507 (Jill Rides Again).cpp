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
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              20001 
int value[MX];
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,t,tc=0;
    sc(t);
    while(t--)
    {
        int sum=0,mx_sum=0,lf=0,ri=0,idx=0;
        sc(n);
        --n;
        for(int i=1; i<=n; i++)
            sc(value[i]);
        for(int i=1; i<=n; i++)
        {


            sum+=value[i];
            if(sum<0)
            {
                sum=0;
                idx=i;
            }
            if(sum>mx_sum||(sum==mx_sum&&ri-lf<i-idx))
            {
                mx_sum=sum;
                lf=idx;
                ri=i;


            }
        }


        if(mx_sum<=0 )
        {
            printf("Route %d has no nice parts\n",++tc);
        }
        else
        {
            printf("The nicest part of route %d is between stops %d and %d\n",++tc,lf+1,ri+1);
        }
    }
    return 0;
}
