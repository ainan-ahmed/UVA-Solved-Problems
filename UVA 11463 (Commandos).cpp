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
#define MX              101

int cost[MX][MX];

void floyd_warshall(int n)
{


    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j])
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }


}
int main()
{

   // freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    int t,tc,n,r,x,y;
    sc(t);
    tcs(tc,t)
    {

        sc(n);
        sc(r);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                    cost[i][j]=INF;
                    else
                        cost[i][i]=0;
            }
        }
        for(int i=1; i<=r; i++)
        {
            sc2(x,y);
            cost[x][y]=1;
            cost[y][x]=1;
        }
        sc2(x,y);
        int ans=0;
        floyd_warshall(n);

        for(int i=0; i<n; i++)
        {

            ans=max(ans,cost[x][i]+cost[i][y]);

        }
        printf("Case %d: %d\n",tc,ans);

    }
    return 0;
}
