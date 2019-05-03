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
#define sc5(a,b,c,d,e)    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
 #define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              104
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int ara[MX],ara2[MX];
int dp[MX][MX],n,m;
int LCS(int i,int j)
{
    if(i==n||j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(ara[i]==ara2[j])ans=1+LCS(i+1,j+1);
    else
    {
        int f1=LCS(i+1,j);
        int f2=LCS(i,j+1);
        ans=max(f1,f2);
    }

    dp[i][j]=ans;
    return dp[i][j];
}

int main()
{

       // freopen("input.txt","r",stdin);
      //  freopen("output.txt","w",stdout);
        int t=0;
         while(sc2(n,m)&&n!=0&&m!=0)
         {
             mmset(dp,-1);
             for(int i=0;i<n;i++)sc(ara[i]);
             for(int j=0;j<m;j++)sc(ara2[j]);
             int ans=LCS(0,0);
              printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++t,ans);


         }

    return 0;
}
