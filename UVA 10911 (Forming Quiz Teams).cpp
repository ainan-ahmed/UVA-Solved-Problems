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
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              202
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
char name[22];
int n;
double dp[(1<<16)+5];
pii coord[18];
double call(int i,int j)
{
    double xx=coord[i].first-coord[j].first;
    double yy=coord[i].second-coord[j].second;
    xx*=xx;
    yy*=yy;
    return sqrt(xx+yy);
}
double calc(int mask)
{
   //  cout<<mask<<" "<<dp[mask]<<endl;
    if(mask==(1<<n)-1)return 0;

    if(dp[mask]!=0)return dp[mask];

    double ans=2e9;
    for(int i=0;i<n;i++)
    {

        if(!check(mask,i))
        {
            for(int j=i+1;j<n;j++)
            {
                if( !check(mask,j))
                {
                   double tmp=call(i,j);
                   // cout<<tmp<<endl;
                    int z=mask;
                    z=Set(z,i);
                    z=Set(z,j);
                    ans=min(ans,calc(z)+tmp);

                }
            }
        }



    }
    return dp[mask]=ans;
}
int main()
{

     freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    int tc=0;
     while(sc(n)&&n!=0)
     {

         n*=2;
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%s%d%d",name,&coord[i].first,&coord[i].second);


        }
        mmset(dp,0);
        printf("Case %d: %.2lf\n",++tc,calc(0));

     }
    return 0;
}
