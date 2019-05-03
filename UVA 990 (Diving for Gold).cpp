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
#define MX               1100
int dp[MX][MX];
int dir[MX][MX];
int cost[MX],depth[MX];
int n,t,w;
vector<pii>ans;
int  knapsack(int idx,int d)
{
    if(idx == n+1)return 0;
    if(d>t)
        return 0;
    if(dp[idx][d]==-1)
    {
        int p1=0,p2=0;
        if(d+3*depth[idx]*w<=t)
        {
            p1=cost[idx]+knapsack(idx+1,d+3*depth[idx]*w);
        }
        p2=knapsack(idx+1,d);
        if(p1>p2)
        {
            dir[idx][d]=1;
            dp[idx][d]=p1;
        }
        else
        {
            dir[idx][d]=2;
            dp[idx][d]=p2;
        }


    }
//    cout<<idx<<" "<<d<<" "<<dp[idx][d]<<endl;
    return dp[idx][d];
}
void printing_path(int i,int d)
{

    while(dir[i][d]!=-1)
    {


        if(dir[i][d]==1)
        {
            ans.pb(mkp(depth[i],cost[i]));
            //cout<<depth[i]<<" "<<cost[i]<<endl;
            d+=depth[i]*3*w;
            i++;

        }
        else
            i++;

    }
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    bool flag=0;
    while(sc2(t,w)==2)
    {
        if(flag)
             printf("\n");
        flag=1;
        sc(n);
        for(int i=1; i<=n; i++)
        {
            sc2(depth[i],cost[i]);

        }
        mmset(dp,-1);
        mmset(dir,-1);
        Pr(knapsack(1,0));
        printing_path(1,0);
        int len=ans.size();
        Pr(len);
        for(int i=0;i<len;i++)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);

        }
        ans.clear();

    }
    return 0;
}
