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
#define MX              1001
int d[MX];
piii pr[2001];
void bellman_Ford(int n,int source,int m)
{
    for(int i=0; i<=n; i++)
    {
        d[i]=INF;
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

        }
    }
    for(int i=1; i<=m; i++)
    {

        int u=pr[i].second.first;
        int v=pr[i].second.second;
        int w=pr[i].first;
        if(d[u]+w<d[v])
        {

            printf("possible\n");
            return;
        }
    }
    printf("not possible\n");

}
int main()
{

    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    int t;
    sc(t);

    int n,m;

    while(t--)
    {
        sc2(n,m);

        for(int i=1; i<=m; i++)
        {
            sc3(pr[i].second.first,pr[i].second.second,pr[i].first);
        }
        bellman_Ford(n,0,m);

    }
    return 0;
}
