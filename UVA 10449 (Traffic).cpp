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
#define MX              40000
int busyness[MX];
int d[MX];

piii pr[MX];

void bellman_Ford(int n,int source,int m)
{
    bool flag=0;
    for(int i=1; i<=n; i++)
    {
        d[i]=INF;
    }
    d[source]=0;
    for(int steps=1; steps<=n-1; steps++)
    {
        flag=0;
        for(int i=1; i<=m; i++)
        {

            int u=pr[i].second.first;
            int v=pr[i].second.second;
            int w=pr[i].first;
            if(d[u]+w<d[v]&&d[u]!=INF)
            {
                flag=1;
                d[v]=d[u]+w;


            }


        }
        if(!flag)
                break;
    }

    for(int i=1; i<=m; i++)
    {

        int u=pr[i].second.first;
        int v=pr[i].second.second;
        int w=pr[i].first;
        if(d[u]+w<d[v]&&d[u]!=INF)
        {
             d[v]=-INF;


        }
    }


}
int main()
{

      //  freopen("input.txt","r",stdin);
     //   freopen("output.txt","w",stdout);
    int n,m,x,q,tc=1;

    while(sc(n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            sc(busyness[i]);
        }
        sc(m);
        for(int i=1; i<=m; i++)
        {
            sc2(pr[i].second.first,pr[i].second.second);
            int xx=pr[i].second.first;
            int yy=pr[i].second.second;
            pr[i].first=(busyness[yy]-busyness[xx])*(busyness[yy]-busyness[xx])*(busyness[yy]-busyness[xx]);


        }
        bellman_Ford(n,1,m);

        sc(q);
        printf("Set #%d\n",tc++);
        for(int i=1;i<=q;i++)
        {
            sc(x);
            if(d[x]<3||d[x]==INF)
                printf("?\n");
            else
            printf("%d\n",d[x]);
        }


    }
    return 0;
}
