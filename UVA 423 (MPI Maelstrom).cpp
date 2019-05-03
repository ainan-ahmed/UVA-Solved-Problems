
#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 100001
#define mkp make_pair
#define pii pair<int,int>
vector<pair<int,int> >edges[MX];
long long d[MX];
void dijkstra(int source)
{
   for(int i=1;i<=MX;i++)d[i]=LONG_LONG_MAX;
    priority_queue<pii,vector< pii >,greater< pii > > pq;
    d[source]=0;
    pq.push(mkp(d[source],source));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i].first;
            int weight=edges[u][i].second;
            if(d[u]+weight<d[v])
            {
                d[v]=d[u]+weight;
               // cout<<v<<" "<<d[v]<<endl;
                pq.push(mkp(d[v],v));
            }
        }
    }


}
int main()
{

    // freopen("input.txt","r",stdin);
     //  freopen("output.txt","w",stdout);
    int n,val=0,temp;
    string s;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            cin>>s;
            val=0;
            if(s=="x")continue;
            stringstream ss(s);
            ss>>val;


          //  cout<<i<<" "<<j<<" "<<val<<endl;
            edges[i].push_back(mkp(j,val));
            edges[j].push_back(mkp(i,val));
        }

    }
    dijkstra(1);
    long long ans=INT_MIN;
    for(int i=2;i<=n;i++)ans=max(ans,d[i]);
        printf("%I64d\n",ans);

        return 0;
}
