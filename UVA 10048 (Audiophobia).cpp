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
#define MX              102
int cost[MX][MX];
void floyd_Warshall(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]>max(cost[i][k],cost[k][j]))
                    cost[i][j] =max(cost[i][k],cost[k][j]);
            }
        }
    }

}
int main()
{

     freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
        int n,s,q,x,y,w,tc=1;
        while(sc3(n,s,q)&&n!=0)
        {
            if(tc!=1)
            printf("\n");
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j)cost[i][j]=0;
                    else
                        cost[i][j]=INF;
                }
            }
            for(int i=1;i<=s;i++)
            {
                sc3(x,y,w);
                cost[x][y]=w;
                cost[y][x]=w;

            }
            floyd_Warshall(n);
            printf("Case #%d\n",tc++);
            for(int i=1;i<=q;i++)
            {
                sc2(x,y);
                if(cost[x][y]==INF)
                    printf("no path\n");
                else
                    printf("%d\n",cost[x][y]);

            }

        }
    return 0;
}
