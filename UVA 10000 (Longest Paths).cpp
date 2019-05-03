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
#define MX               102
int level[MX];
vi edges[MX];
int idx,mx=-INF;
void bfs(int source)
{
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int len=edges[u].size();
        for(int i=0;i<len;i++)
        {

            int v=edges[u][i];
            if(v==source||v==u)return;
            if(level[v]<level[u]+1)
            {
                level[v]=level[u]+1;
                if(level[v]>mx||(level[v]==mx&&v<idx))
                {
                    mx=level[v];
                    idx=v;
                }
                q.push(v);
            }
        }

    }
}
int main()
{

   // freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
    int n,start,x,y,tc=0;
    while(sc(n)&&n!=0)
    {

        mx=-INF,idx=200;
        sc(start);
        while(sc2(x,y)&&x!=0&&y!=0)
        {
            edges[x].pb(y);
        }
        bfs(start);
        if(mx==-INF)mx=0,idx=start;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++tc,start,mx,idx);
        for(int i=1;i<=n;i++)
            edges[i].clear(),level[i]=0;
            \
    }
    return 0;
}
