#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define sc4(a,b,c,d)      scanf("%d%d%d%d",&a,&b,&c,&d)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define MX  20001
int n,m,S,t,T;
vector<pii>edges[MX];
int d[MX];
bool dijkstra(int source)
{
   for(int i=0;i<MX;i++)d[i]=INT_MAX;
    priority_queue<pii,vector<pii >,greater< pii > > pq;
    d[source]=0;
    pq.push(make_pair(d[source],source));
    while(!pq.empty())
    {
        pii a=pq.top();
        int u=a.second;
        pq.pop();
        int len=edges[u].size();
        for(int i=0;i<len;i++)
        {
            pii v=edges[u][i];
            if(d[u]+v.second<d[v.first])
            {
                d[v.first]=d[u]+v.second;
               // cout<<v<<" "<<d[v]<<endl;
                pq.push(make_pair(d[v.first],v.first));
            }
        }
    }


}
void init()
{

        for(int i=0;i<MX;i++)
            edges[i].clear();

}
int main()
{

   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    sc(t);
    int x,y,w;
    for(int tc=1;tc<=t;tc++)
    {
        sc4(n,m,S,T);
        for(int i=1;i<=m;i++)
        {
            sc3(x,y,w);
            edges[x].pb(make_pair(y,w));
            edges[y].pb(make_pair(x,w));


        }
        printf("Case #%d: ",tc);
        dijkstra(S);
        if(d[T]==INT_MAX)
        {
            printf("unreachable\n");
        }
        else
        {
            Pr(d[T]);
        }
        init();

    }
    return 0;
}

