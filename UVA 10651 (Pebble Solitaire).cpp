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
#define MX              1010
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int inp;
string s;
int dp[(1<<12)+2];
int calc(int mask)
{
  // if(mask==0)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int mn = __builtin_popcount(mask);

    for(int i=0; i<12; i++)
    {



        if(check(mask,i))
        {
            if(i+2<12&&check(mask,i+1)&&!check(mask,i+2))
            {

                int temp=mask;
                temp=reset(temp,i);
                temp=reset(temp,i+1);
                temp=Set(temp,i+2);
                mn=min(mn,calc(temp));
            }
            if(i-2>=0&&check(mask,i-1)&&!check(mask,i-2))
            {

                int temp=mask;
                temp=reset(temp,i);
                temp=reset(temp,i-1);
                temp=Set(temp,i-2);
                mn=min(mn,calc(temp));
            }
        }

    }
    return dp[mask]=mn;
}
int main()
{

    freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    int n;
    sc(n);

    for(int i=1; i<=n; i++)
    {
        mmset(dp,-1);
        getchar();
        cin>>s;

        inp=0;
        int  cnt=0;

        for(int j=0; j<12; j++)
        {

            if(s[j]=='o')
            {
               inp= Set(inp,j);
                cnt++;
            }

        }

         Pr(calc(inp));
    }

    return 0;
}

