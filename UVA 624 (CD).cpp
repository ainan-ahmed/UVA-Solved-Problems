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
#define MX              100000007
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int ara[22];
int n,x,mx=-INF;
vi v,ans;
void call(int i,ll sum)
{
    if(sum>n)return;
    if(sum>mx)
    {
        ans.clear();
        int len=v.size();
        for(int i=0;i<len;i++)
        {
            ans.pb(v[i]);
        }
        mx=sum;

    }
   for(int j=i;j<x;j++)
   {
       if(sum+ara[j]<=n)
       {
            v.pb(ara[j]);
            call(j+1,sum+ara[j]);
            v.pop_back();

       }
   }
}
int main()
{

          freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);

            while(sc(n)==1)
            {
                mx=-INF;
                sc(x);
                for(int i=0;i<x;i++)
                {
                    sc(ara[i]);
                }
               // mmset(dp,-1);
               // ll ans=knapsack(0,0);
                call(0,0);
                int len=ans.size();
                for(int i=0;i<len;i++)
                    printf("%d ",ans[i]);
               printf("sum:%d\n",mx);



            }
    return 0;
}
