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
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX               305
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int coins1[45],coins2[45] ;
int dp[MX][MX] ;
void calc(int n,int s)
{
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=coins1[i];j<=s;j++)
        {
            for(int k=coins2[i];k<=s;k++)
            {
                 dp[j][k]=min(dp[j][k],dp[j-coins1[i]][k-coins2[i]]+1);
            }
        }
    }
}
void CLR()
{
    mmset(dp,INF);
}
int main()
{
          freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
        int t,n,s;

        sc(t);
        tcs(t)
        {
           // if(tc!=1)printf("\n");
            sc2(n,s);
            for(int i=1;i<=n;i++)
            {
                sc2(coins1[i],coins2[i]);

            }
            CLR();
            calc(n,s);

            int mn=INF;

            for(int i=0;i<=s;i++)
            {
                for(int j=0;j<=s;j++){
                if(i*i+j*j==s*s)
                {
                        mn=min( dp[i][j],mn);
                }
            }
            }
            if(mn!=INF)
                    Pr(mn);

            else
                printf("not possible\n");
        }

    return 0;
}
