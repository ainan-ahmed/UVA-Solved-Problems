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
#define MX               33000
vi ara;
vi I;
int LIS()
{
    int sz=ara.size();
     reverse(all(ara));
     I.pb(-INF);
       for(int i=1;i<=sz;i++)
       {
           I.pb(INF);

       }
    int len=0;
    for(int i=0;i<sz;i++)
    {
        int low=0,high=len,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<=ara[i])
                low=mid+1;
                else
                    high=mid-1;
        }
        I[low]=ara[i];
        if(low>len)
            len=low;
    }
    return len;
}
int main()
{

     freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    int t,a,tc=0;
    bool flag=0;
    while(sc(t)&&t!=-1)
    {
        if(flag)printf("\n");
        flag=1;
        ara.pb(t);
        while(sc(a)&&a!=-1)
        {
            ara.pb(a);
        }
       printf("Test #%d:\n  maximum possible interceptions: %d\n",++tc,LIS());
        ara.clear();
        I.clear();
    }
    return 0;
}
