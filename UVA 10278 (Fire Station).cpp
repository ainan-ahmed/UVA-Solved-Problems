#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
#define vii             vector<int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)           printf("%lld\n",a)
#define MX  1000
vector<int>edges[MX];
int d[MX];
int cost[MX][MX];
map<int,int>mp;
int t,f,is;
int dijkstra(int source)
{
     priority_queue<pii,vector< pii >,greater< pii > > pq;
    for(int i=1; i<=is; i++){
            if(mp[i]!=0){
                    d[i]=0;
                    pq.push(mkp(0,i));

            }
    else
        d[i]=INT_MAX;
    }

    d[source]=0;
    pq.push(mkp(d[source],source));
    while(!pq.empty())
    {

        int u=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        int len=edges[u].size();
        for(int i=0; i<len; i++)
        {
            int v=edges[u][i];
            // cout<<u<<" "<<v<<" "<<cost[u][v]<<endl;
            if(dis+cost[u][v]<d[v])
            {
                d[v]=dis+cost[u][v];
                pq.push(mkp(d[v],v));
            }

        }

    }
    int mx=INT_MIN;
    for(int i=1; i<=is; i++)
    {
       // cout<<i<<" "<<d[i]<<endl;
        mx=max(mx,d[i]);
    }
    return mx;
}
int main()
{

   // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    sc(t);
    int x,y,dis;
    while(t--)
    {
        sc2(f,is);
       // vector<int>v;
        for(int i=1; i<=f; i++)
        {
            sc(x);
            mp[x]++;
          //  v.push_back(x);
        }
        string s;
        getchar();
        while(1)
        {
            getline(cin,s);
            if(s=="")
                break;
            stringstream ss(s);
            ss>>x>>y>>dis;
            edges[x].push_back(y);
            edges[y].push_back(x);
            cost[x][y]=dis;
            cost[y][x]=dis;
        }
        int xx,mn=INT_MAX,ans=1;
        for(int i=1; i<=is; i++)
        {
            if(mp[i]!=0)continue;
            xx=dijkstra(i);
            //  cout<<"\n\n"<<i<<" "<<xx<<endl;
            if(mn>xx)
            {
                mn=xx;
                ans=i;
            }


        }


        Pr(ans);
        if(t!=0)
        printf("\n");
        mp.clear();
        for(int i=1;i<=is;i++)
            edges[i].clear();
        mmset(cost,0);

    }


    return 0;
}

