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
int maze[MX][MX];
int d[MX][MX];
int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};
int t,n,m;
bool dijkstra(pii source)
{

   d[source.first][source.second]=maze[source.first][source.second];
    priority_queue<piii,vector< piii >,greater< piii > > pq;
    pq.push(make_pair(d[source.first][source.second],source));
    while(!pq.empty())
    {
        pair<int,pii> a=pq.top();
        pii u=a.second;
        int dis=a.first;
        pq.pop();
        for(int k=0;k<4;k++)
        {
            int tx=u.first+fx[k];
            int ty=u.second+fy[k];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&dis+maze[tx][ty]<d[tx][ty])
            {
                d[tx][ty]=dis+maze[tx][ty];
                pq.push(mkp(d[tx][ty],pii(tx,ty)));
             //   cout<<tx<<" "<<ty<<" "<<d[tx][ty]<<endl;
            }
        }
    }


}
int main()
{

    //freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);

        sc(t);
        while(t--)
        {
            sc2(n,m);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    sc(maze[i][j]);
                    d[i][j]=INT_MAX;

                }
            }
            dijkstra(pii(0,0));
            Pr(d[n-1][m-1]);

        }


    return 0;
}

