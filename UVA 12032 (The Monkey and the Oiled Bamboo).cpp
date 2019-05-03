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
#define MX              100005
int ara[MX];
bool solve(int x,int n)
{
    int curr=0;
    for(int i=1;i<=n;i++)
    {
        if(ara[i]-curr>x){

           return false;
        }
        else if(ara[i]-curr==x)
        {
            --x;
        }

         curr=ara[i];
    }

    return true;
}
int main()
{

      freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
    int tc,t,n,ans=-1,prev;
    int diff;
    sc(t);
    tcs(tc,t)
    {
        sc(n);
        prev=0;
        ans=-1;
        diff=-INF;
        for(int i=1;i<=n;i++){
            sc(ara[i]);
            diff=max((ara[i]-prev),diff);
            prev=ara[i];
        }
        if(n==1)
        {
            printf("Case %d: %d\n",tc,ara[1]);
            continue;
        }

        int low=0,high=diff;

        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(solve(mid,n))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }

        if(ans==-1)
            printf("Case %d: %d\n",tc,diff+1);
        else
        printf("Case %d: %d\n",tc,ans);


    }
    return 0;
}
