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
#define scll4(a,b,c,d)    scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF 0x3f3f3f3f
#define MX  21
double cost[MX][MX][MX];
int path[MX][MX][MX];
int ans1=-1,ans2=-1;
void floyd_warshall(int n)
{

    for(int step=2; step<=n; step++)
    {
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(cost[step][i][j]<cost[step-1][i][k]*cost[1][k][j])
                    {
                        cost[step][i][j]=cost[step-1][i][k]*cost[1][k][j];
                        path[step][i][j]=path[step-1][i][k];

                         /*if(i==j&&cost[step][i][j]>1.01)
                         {

                             ans1=i,ans2=step;
                             cout<<ans1<<" "<<ans2<<endl;
                             return;
                         }*/
                    }
                }
            }
        }
    }



}
int main()
{

    // freopen("input.txt","r",stdin);
     //    freopen("output.txt","w",stdout);
    int n;
    while(sc(n)!=EOF)
    {
        for(int step=1; step<=n; step++)
        {
            for(int i =1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cost[step][i][j]=0;
                    path[step][i][j]=j;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    cost[1][i][j]=1.0;
                else
                    scanf("%lf",&cost[1][i][j]);
            }
        }
        floyd_warshall(n);
        bool flag=false;
        for(int step=2; step<=n&&!flag; step++)
        {
            for(int i=1; i<=n&&!flag; i++)
            {
                if(cost[step][i][i]>=1.01)
                {
                    flag=true;
                    ans1=i,ans2=step;
                    break;
                }
            }
        }
       // cout<<ans1<<" "<<ans2<<endl;
        if(!flag)
        {
            printf("no arbitrage sequence exists\n");

        }
        else
        {
           // cout<<ans1<<" "<<ans2<<endl;
            int i=ans1,j=ans1;

            while(ans2>=0)
            {
                if(ans2==0){
                    printf("%d\n",i);

                }
                else{
                printf("%d ",i);
                i=path[ans2][i][j];

                }
                ans2--;


            }

        }

        ans1=-1,ans2=-1;
    }
    return 0;
}
