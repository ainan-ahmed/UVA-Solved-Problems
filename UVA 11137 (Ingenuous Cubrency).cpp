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
#define MX               10002
int coins[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
ull dp[22][MX];
ull coin_change(int i,ll amount)
{
    if(i==21)
    {
        if(amount==0)return 1;
        else
            return 0;
    }
    if(amount<0)return 0;
    if(amount ==0)return 1;
    if(dp[i][amount]==-1)
    {
        ull f1=0,f2=0;
        if(amount-coins[i]>=0)
            f1=coin_change(i,amount-coins[i]);
        f2=coin_change(i+1,amount);
        dp[i][amount]=f1+f2;
    }
    return dp[i][amount];
}
int main()
{

   // freopen("input.txt","r",stdin);
   //   freopen("output.txt","w",stdout);
    ll n;
    mmset(dp,-1);
    while(scll(n)==1){

    printf("%llu\n",coin_change(0,n));

    }
    return 0;
}
