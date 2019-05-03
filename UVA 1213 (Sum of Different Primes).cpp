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
#define MX              1125
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int primes[MX];
bool flag[MX];
ll dp[MX][16][188];
int total, n,k;
void sieve()
{

    for(int i=4;i<=MX;i+=2)
        flag[i]=1;
    int sq=sqrt(MX)+1;

        for(int i=3;i<=sq;i+=2)
        {
            if(flag[i]==0)
            {
                for(int j=i*i;j<=MX;j+=i)
                {
                    flag[j]=1;
                }



            }
        }
        for(int i=2;i<=MX;i++)
        {
            if(!flag[i])
                primes[total++]=i;
        }

}
ll calc(int i,int rem,int cnt)
{

    if(cnt>k)return 0;
     if(rem<0)return 0;
    if(dp[rem][cnt][i]!=-1)return dp[rem][cnt][i];
    if(i==total)
    {
        if(rem==0){
            if(cnt==k)
                return 1;
            else
            return 0;
        }
        else return 0;
    }


    if(rem==0){
            if(cnt==k)
                return 1;
            else
            return 0;
        }


    ll f1=0,f2=0;

        f1 =calc(i+1,rem-primes[i],cnt+1);
        f2 =calc(i+1,rem,cnt);

        dp[rem][cnt][i]=f1+f2;
        return dp[rem][cnt][i];

}
int main()
{

           freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
         sieve();

       while(sc2(n,k)&&(n!=0&&k!=0))
       {

            mmset(dp,-1);
            ll ans=calc(0,n,0);
            cout<<ans<<endl;
       }

    return 0;
}
