#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<pii,int>
#define vi              vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
#define mmset(a,val)    memset(a,val,sizeof(a))
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define SZ              size()
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define hash_val        347
#define popcount        __builtin_popcount
#define MOD             1000000007
#define MX              1000005
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
double dp[MX];
bool visited[MX];
int primes[MX];
void sieve()
{
    for(int i=4;i<=MX;i+=2)
        visited[i]=1;
    int sq=sqrt(MX)+1;
            int total=0;
        for(int i=3;i<=sq;i+=2)
        {
            if(visited[i]==0)
            {
                for(int j=i*i;j<=MX;j+=i)
                {
                    visited[j]=1;
                }



            }
        }
        for(int i=2;i<=MX;i++)
        {
            if(!visited[i])
                primes[total++]=i;
        }

}
double dfs(int u)
{

    if(u==1)return 0;
    if(visited[u])
        return dp[u];
    dp[u]=0;
    visited[u]=1;
    int d=0,div=0;
    for(int i=0;primes[i]<=u&&primes[i]>0;i++)
    {
        d++;
         if(u%primes[i]==0){
        dp[u]+=dfs(u/primes[i]);
        div++;
         }
    }
    dp[u]+=d;
    dp[u]/=(div);
    return dp[u];
}
int main()
{
                freopen("input.txt","r",stdin);
            //  freopen("output.txt","w",stdout);
            int t;
            sieve();
            sc(t);
            tcs(t)
            {
                 int n;
                 sc(n);
                 mmset(visited,0);
                 printf("Case %d: %.8lf\n",tc,dfs(n));


            }

}
