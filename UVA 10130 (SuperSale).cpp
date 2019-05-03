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
#define MX              1002
int dp[MX][MX];
bool visited[MX][MX];
int cost[MX],weight[MX];
int n;
int  knapsack(int idx,int w,int lim)
{
    if(idx == n+1)return 0;
    if(!visited[idx][w])
    {
        visited[idx][w]=1;
        int  p1=0,p2=0;
        if(w+weight[idx]<=lim)
            p1=cost[idx]+knapsack(idx+1,w+weight[idx],lim);
        p2=knapsack(idx+1,w,lim);
        dp[idx][w]=max(p1,p2);
    }
    return dp[idx][w];
}
int main()
{

    freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    int tc,t,a;
    sc(t);
    tcs(tc,t)
    {
        sc(n);
        for(int i=1; i<=n; i++)
        {
            sc2(cost[i],weight[i]);

        }
        int q;
        sc(q);
        int ans=0;
        for(int i=1; i<=q; i++)
        {
            mmset(visited,0);
            sc(a);
            ans+=knapsack(1,0,a);
        }
        Pr(ans);

    }
    return 0;
}
