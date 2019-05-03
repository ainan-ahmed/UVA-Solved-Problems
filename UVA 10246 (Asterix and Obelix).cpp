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
#define MX              82
int cost[MX][MX];
int feast[MX][MX];
void floyd_warshall(int n)
{


    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(cost[i][j]+feast[i][j]>cost[i][k]+cost[k][j]+max(feast[i][k],feast[k][j]))
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                    feast[i][j]=max(feast[i][k],feast[k][j]);
                }
            }
        }
    }


}
int main()
{

   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int t,tc=1,n,r,q,x,y,z;


    while(sc3(n,r,q)&&n!=0)
    {


        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                    cost[i][j]=INF;
                else
                    cost[i][i]=0;

            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    sc(feast[i][i]);
                else
                    feast[i][j]=0;

            }

        }
        for(int i=1; i<=r; i++)
        {
            sc3(x,y,z);
            cost[x][y]=z;
            cost[y][x]=z;
            feast[x][y]=feast[y][x]=max(feast[x][x],feast[y][y]);
        }
        floyd_warshall(n);
        floyd_warshall(n);
        if(tc!=1)
            printf("\n");
        printf("Case #%d\n",tc++);
        for(int i=1; i<=q; i++)
        {
            sc2(x,y);
            if(cost[x][y]==INF)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",cost[x][y]+feast[x][y]);
            }



        }

    }
    return 0;
}
