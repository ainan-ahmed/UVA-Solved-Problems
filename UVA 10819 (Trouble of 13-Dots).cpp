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
#define MX              105
pii value[MX];
int m,n;
int dp[MX][10205];
int call(int i,int used)
{
  //  cout<<i<<" "<<used<<" "<<fav<<endl;
    if((used>m&&m<=1800)||(used>m+200))
                return -INF;


    if(i==n+1)
    {
        if(used>m&&used<=2000)
            return -INF;
        return 0;
    }
    if(dp[i][used]==-1)
    {
        int f1=0,f2=0;
        f1=call(i+1,used+value[i].first)+value[i].second;
        f2=call(i+1,used);
        dp[i][used]=max(f1,f2);
    }
    return dp[i][used];
}
int main()
{

    // freopen("input.txt","r",stdin);
   //    freopen("output.txt","w",stdout);
    while(sc2(m,n)==2)
    {

        mmset(dp,-1);
        for(int i=1;i<=n;i++)
        {
            sc2(value[i].first,value[i].second);
        }

       Pr(call(1,0 ));
    }

    return 0;
}
