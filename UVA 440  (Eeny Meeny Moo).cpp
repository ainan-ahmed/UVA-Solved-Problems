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
#define MX              101
ll josephus(ll n,ll k)
{
    if(n==1)return 1;
    else
    {
        return ((josephus(n-1,k)+k-1)%n+1);
    }
}
int main()
{

  //  freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int n,k,val;
    while(sc(n))
    {
        if(n==0)return 0;
        for(int i=2;i<=1000;i++)
        {
            val=josephus(n-1,i);
           // cout<<n<<" "<<val<<endl;
            if(val==1)
            {
                printf("%d\n",i);
                break;
            }
        }

    }
    return 0;
}


