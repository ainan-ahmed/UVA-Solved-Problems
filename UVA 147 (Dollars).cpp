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
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              30002
#define MOD             10000007
int coins[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll make;
ll dp[11][MX];
ll coin_change(int i,ll amount)
{
    if(i>=11)
    {
        if(amount==0)return 1;
        else return 0;
    }
    if(amount<0)return 0;
    if(amount==0)return 1;
    if(dp[i][amount]==-1)
    {
        ll f1=0,f2=0;

       if(amount-coins[i]>=0)
        {
            f1=coin_change(i,amount-coins[i]);
        }
        f2=coin_change(i+1,amount);
        dp[i][amount]=f1+f2;
    }
    return dp[i][amount];
}
int main()
{

    //freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
     mmset(dp,-1);
     float n;
     while(scanf("%f",&n))
     {
         if(n==0.00)return 0;
         make=(ll)(n*100+0.5);
        // cout<<make<<endl;
         printf("%6.2f%17lld\n",n,coin_change(0,make));

     }

    return 0;
}
