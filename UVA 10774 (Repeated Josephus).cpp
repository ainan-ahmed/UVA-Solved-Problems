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
int josephus(int n)
{

     int p=1;
     while(p<=n)p*=2;
     return 2*n-p+1;
}
int main()
{

   // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int n,k,tc,t,cnt=0,val;
    sc(t);
    tcs(tc,t)
    {
        cnt=0;
        sc(n);
        if(n==0)return 0;
        val=josephus(n);
        //cout<<n<<" "<<val<<endl;
       if(n!=1 && val != n )
            cnt++;
       while(val!=n)
        {
            n=val;
            val=josephus(n);
            if(val==n)break;
            //cout<<n<<" "<<val<<endl;
            cnt++;
        }

        printf("Case %d: %d %d\n",tc,cnt,n);




    }
    return 0;
}


