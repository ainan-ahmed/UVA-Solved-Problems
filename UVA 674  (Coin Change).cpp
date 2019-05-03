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
#define MX               7490
int coins[]={50,25,10,5,1};
int make;
int dp[6][MX];
int coin_change(int i,int amount)
{
    if(i>=5)
    {
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]==-1)
    {
        int f1=0,f2=0;
        if(amount-coins[i]>=0)
            f1=coin_change(i,amount-coins[i]);
        f2=coin_change(i+1,amount);
        dp[i][amount]=f1+f2;
    }
    return dp[i][amount];
}
int main()
{

    //  freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    mmset(dp,-1);
    while(sc(make)!=EOF)
    {

        Pr(coin_change(0,make));
    }

    return 0;
}
