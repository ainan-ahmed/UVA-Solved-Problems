#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
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
#define MX              1005
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int ara[MX],ara2[MX];
int dp[MX],n,m;
void LCIS()
{
   for(int i=0;i<n;i++)
   {
       int curr=0,last=-1;
       for(int j=0;j<m;j++)
       {

           if(ara[i]==ara2[j]&&curr+1>dp[j])
           {
                dp[j]=curr+1;
              //  parent[j]=last;
           }
           else if(ara[i]>ara2[j]&&dp[j]>curr)
           {
                curr=dp[j];
                last=j;
           }


       }
   }
   int ans=0,idx=-1;
   for(int i=0;i<m;i++)
   {
       if(ans<dp[i])
       {
           ans=dp[i];
           idx=i;
       }
   }


    Pr(ans);
  /*  vi v;
    while(idx!=-1)
    {
        v.pb(ara2[idx]);
        idx=parent[idx];
    }
    for(int i=ans-1;i>=0;i--){
        printf("%d",v[i]);
        if(i>0)printf(" ");

    }
    printf("\n");*/
}
int main()
{

          freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
            int t;
            sc(t);
            while(t--){
            sc(n);
            for(int i=0;i<n;i++)sc(ara[i]);
            sc(m);
            for(int j=0;j<m;j++)sc(ara2[j]);
            mmset(dp,0);
          //  mmset(parent,0);
          LCIS();


            }

    return 0;
}
