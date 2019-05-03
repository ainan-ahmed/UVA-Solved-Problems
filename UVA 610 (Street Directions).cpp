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
int  d[MX],low[MX] ;
bool bridges[MX][MX],visited[MX];
vi edges[MX];
int T;
set<pii>st;
void art_bridges(int u,int prev)
{
    T++;
    d[u]=low[u]=T;
    visited[u]=1;
    int len=edges[u].size() ;
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(v==prev)continue;
        if(visited[v]){
            low[u]=min(low[u],d[v]);
             if(!bridges[v][u])bridges[u][v]=1;
        }
        else{

            art_bridges(v,u);
            low[u]=min(low[v],low[u]);
            if(d[u]< low[v])
            {
                bridges[u][v]=bridges[v][u]=1;

            }
            else if(!bridges[v][u])bridges[u][v]=1;

        }
    }
}
void CLR()
{
    for(int i=0;i<MX;i++)
        edges[i].clear();
    mmset(visited,0);
    mmset(bridges,0);

}
int main()
{
       //   freopen("input.txt","r",stdin);
       //    freopen("output.txt","w",stdout);
            int t=0,n,m,x,y;

            while(sc2(n,m)&&n&&m)
            {

                CLR();
                for(int i=1;i<=m;i++)
                {
                    sc2(x,y);
                    edges[x].pb(y);
                    edges[y].pb(x);
                }
                art_bridges(1,-1);
                printf("%d\n\n",++t);
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(i==j||bridges[i][j]==0)continue;
                        printf("%d %d\n",i,j);
                        bridges[i][j]=0;
                        if(bridges[j][i])
                        {
                            printf("%d %d\n",j,i);
                            bridges[j][i]=0;
                        }
                    }

                }
                 printf("#\n");

            }

    return 0;
}

