#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define fast()          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
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
#define MX              105
//int fx[]={0,0,-1,1,-1,1,-1,1};
//int fy[]={-1,1,0,0,1,1,-1,-1};
ll Set(int n,int pos){return n=n|( 1LL << pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
vi v;
int main()
{
            #ifdef AINAN
                 freopen("input.txt","r",stdin);
              //   freopen("output.txt","w",stdout);
             #endif
     int n,a,ans1=0,ans2=0;

    while(sc(n)!=EOF)
    {

        for(int i=1 ; i<=n;i++)
        {
            sc(a);
            v.pb(a);
        }
        sort(all(v));
        ll d;
        scll(d);
        int low=0,high=n-1;
        ll sum=v[low];
        while(low<high)
        {
            sum+=v[high];
            if(sum==d)
            {
                ans1=v[low];
                ans2=v[high];
                low++,high--;
                sum=v[low];
            }
            else if(sum>d)
            {
                sum-=v[high];
                high--;
            }
            else
            {
                low++;
                sum=v[low];
            }

        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);

    v.clear();
    }
    return 0;
}

