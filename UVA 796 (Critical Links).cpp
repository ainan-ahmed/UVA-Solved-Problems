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
#define MX              10006
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int  d[MX],low[MX] ;
bool bridges[MX],visited[MX];
vi edges[MX];
int   t;
vector<pii>ans;
void art_bridges(int u,int prev)
{
    t++;
    d[u]=low[u]=t;
    visited[u]=1;
    int len=edges[u].size() ;
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(v==prev)continue;
        if(visited[v])
            low[u]=min(low[u],d[v]);
        else{

            art_bridges(v,u);
            low[u]=min(low[v],low[u]);
            if( d[u]< low[v]   )
            {
                bridges[u]=1;
                ans.pb((u<v)?mkp(u,v):mkp(v,u));
            }
        }
    }
}
void CLR()
{
    for(int i=0;i<MX;i++)
        edges[i].clear();
    mmset(visited,0);
    mmset(bridges,0);
    ans.clear();
}
int main()
{
          freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
            int tc=0,n,a,x,k;
            char c,c1;

            while(sc(n)==1)
            {


                CLR();


                for(int i=1;i<=n;i++)
                {

                   scanf("%d %c%d%c",&a,&c,&k,&c1);

                     while(k--)
                    {
                        sc(x);
                        edges[a].pb(x);
                        edges[x].pb(a);

                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(!visited[i])
                    {
                        art_bridges(i,-1);
                    }
                }
                 sort(all(ans));
                 int len=ans.size();

                 printf("%d critical links\n",len);

                for(int i=0;i<len;i++)
                {
                    printf("%d - %d\n",ans[i].first,ans[i].second);
                }
             printf("\n");
            }

    return 0;
}

