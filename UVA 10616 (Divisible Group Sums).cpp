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
#define MX              205
int n,d,m,q;
int value[MX];
ll dp[MX][11][22];
ll call(int i,int tot,ll sum)
{
   // cout<<i<<" "<<tot<<" "<<sum<<endl;

    if(tot==m)
    {
        if(sum==0)
        {
            return 1;
        }
        else
            return 0;
    }

    if(i==n+1)return 0;
    if(dp[i][tot][sum]==-1)
    {
        ll tmp=sum+value[i];
        tmp%=d;
        if(tmp<0)tmp+=d;
        ll f1=0,f2=0;

            f1=call(i+1,tot+1,tmp);
            f2=call(i+1,tot,sum%d);

        dp[i][tot][sum]=f1+f2;
    }
    return dp[i][tot][sum];
}
int main()
{

     freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);

    int  tc=0;

    while(sc2(n,q)&&n!=0&&q!=0)
    {
        printf("SET %d:\n",++tc);
        for(int i=1;i<=n;i++)
            sc(value[i]);

        for(int i=1;i<=q;i++)
        {
            sc2(d,m);
            mmset(dp,-1);
          printf("QUERY %d: %lld\n",i,call(1,0,0));

        }
    }
    return 0;
}
