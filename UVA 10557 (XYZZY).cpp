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
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              400000
int cost[MX];
int d[MX];
vector<int>edges[MX];
pii pr[MX];
bool visited[MX];
bool flag;
void dfs(int source,int n)
{
    visited[source]=1;
    if(flag)return;
    int len=edges[source].size();
    for(int i=0; i<len&&!flag; i++)
    {
        int v=edges[source][i];
        if(v==n)
        {
            flag=1;
            return;
        }
        if(!visited[v])
        {
            dfs(v,n);
        }
    }
}
bool check(int u,int v,int n)
{
    flag=0;
    dfs(1,u);
     mmset(visited,0);
    if(flag)
    {
        flag=0;
        dfs(v,n);
         mmset(visited,0);
        if(flag)
        {
            return true;
        }
        else
            return false;
    }
    return false;
}
void bellman_Ford(int n,int source,int m)
{
    bool flag2=0;
   for(int i=1; i<=n; i++)
    {
        d[i]=INF;
    }
    d[source]=-100;
    for(int steps=1; steps<=n-1; steps++)
    {

        flag2=0;
        for(int i=1; i<=m; i++)
        {
            int u=pr[i].first;
            int v=pr[i].second;
            if(d[u]+cost[u]<min(d[v],0))
            {
                flag2=1;
                d[v]=d[u]+cost[u];
            }
        }
        if(d[n]<0)
    {
        printf("winnable\n");
        return;
    }
        if(!flag2)
            break;
    }

        for(int i=1; i<=m; i++)
        {
            int u=pr[i].first;
            int v=pr[i].second;

            if(d[u]+cost[u]<min(d[v],0)&&check(u,v,n))
            {
                 printf("winnable\n");
                return;
            }
        }
        printf("hopeless\n");
}
int main()
{

    freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    int n,m,x,q,tc=1,xx=1,a,k;

    while(sc(n)&&n!=-1)
    {
        xx=1;
        for(int i=1; i<=n; i++)
        {
            sc2(a,k);
            cost[i]=-a;
            for(int j=1; j<=k; j++)
            {
                pr[xx].first=i;
                sc(pr[xx].second);
                edges[i].pb(pr[xx].second);
                xx++;
            }
        }
        --xx;
        bellman_Ford(n,1,xx);

        for(int i=1;i<=MX;i++)
            edges[i].clear();
    }
    return 0;
}
