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
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX              1005
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int d[MX];
piii pr[2005];
bool visited[MX];
vi edges[MX];
vi ans;
bool flag=0;
void dfs(int u)
{
    visited[u]=1;
    ans.pb(u);
    int len=edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(!visited[v])
            dfs(v);
    }
}
void bellman_Ford(int n,int source,int m)
{
    for(int i=0; i<=n; i++){
        d[i] =INF;
    }
    d[source]=0;

    for(int steps=1; steps<=n-1; steps++)
    {
        for(int i=1; i<=m; i++)
        {

            int u=pr[i].second.first;
            int v=pr[i].second.second;
            int w=pr[i].first;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;

            }
            // cout<<u<<" "<<d[u]<<"\t"<<v<<" "<<d[v]<<endl;
        }
    }
    flag=0;
    for(int i=1; i<=m; i++)
    {

        int u=pr[i].second.first;
        int v=pr[i].second.second;
        int w=pr[i].first;
        if(d[u]+w<d[v])
        {
            flag=1;

             d[v]=d[u]+w;
             if(!visited[u])
                dfs(u);
        }
    }




}

int main()
{

          freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
        int n,m,x,y,u,v,w,t;
        sc(t);
        tcs(t){
            sc2(n,m);

            for(int i=1; i<=m; i++)
            {
                sc3(u,v,w);
                pr[i].second.first=v;
                pr[i].second.second=u;
                pr[i].first=w;
                edges[v].pb(u);
            }
                bellman_Ford(n,1,m);
                if(!flag)
                {
                    printf("Case %d: impossible\n",tc);
                }
                else
                {
                    sort(all(ans));
                    int len=ans.size();
                        printf("Case %d:",tc);
                    for(int i=0;i<len;i++)
                        printf(" %d",ans[i]);
                        ans.clear();
                        printf("\n");
                }
                for(int i=0;i<=n;i++)edges[i].clear();
                mmset(pr,0);
                mmset(visited,0);

    }
    return 0;
}

