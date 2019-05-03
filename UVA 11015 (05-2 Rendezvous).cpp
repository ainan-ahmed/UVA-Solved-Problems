#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define tcs(tc,t)          for(int tc=1;tc<=t;tc++)
#define INF 0x3f3f3f3f
#define MX  23
int cost[MX][MX];
string ss[MX];
void floyd_warshall(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(cost[i][j]==0&&i!=j)
            {
                cost[i][j]=INF;
            }

        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j]){
                cost[i][j]= cost[i][k]+cost[k][j] ;
                }
            }
        }
    }


}
int main()
{

   // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
        int n,m,x,y,w,xx=1;
        string s;
        while(sc2(n,m)&& n!=0 )
        {

            for(int i=1;i<=n;i++)
            {
                cin>>s;
                ss[i]=s;
            }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            cost[x][y]=w;
            cost[y][x]=w;

        }

        floyd_warshall(n);
        int ans=INT_MAX,sum,index=1;
        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]==INF)
                {
                    sum=0;
                    break;
                }
                sum+=cost[i][j];
            }
            if(sum<ans)
            {
                ans=sum;
                index=i;
            }
        }
        printf("Case #%d : %s\n",xx++,ss[index].c_str());


        mmset(cost,0);

        }
    return 0;
}
