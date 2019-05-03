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
#define MX               50020
int coins[102];
bool dp[MX];
int main()
{

     freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
        int t ,n,m;
        sc(t);
        while(t--)
        {
            sc(n);
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sc(coins[i]);
                sum+=coins[i];
            }
            mmset(dp,0);
           dp[0]=1;
            for(int i=0;i<n;i++)
            {
                for(int j=sum;j>=0;j--)
                {
                    if(dp[j])
                    {
                        dp[coins[i]+j]=1;
                    }
                }
            }
               for(int i=sum/2;i>=0;i--)
               {
                   if(dp[i])
                   {
                       if(sum&1)
                       Pr(((sum/2)-i)*2 + 1);
                       else
                        Pr(((sum/2)-i)*2);

                       break;
                   }
               }


        }


    return 0;
}
