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
vi value;
int dp[MX];
int dir[MX];
int LIS(int u,int len)
{
    if(dp[u]!=-1)return dp[u];
    int mx=0;
    for(int v=u+1; v<len; v++)
    {
        if(value[v]<=value[u])
        {
            int tmp=LIS(v,len);
            if(tmp>mx)
            {
                mx=tmp;
                dir[u]=v;
            }

        }
    }
    dp[u]=1+mx;
    return dp[u];
}
void printing_path(int start)
{
    cout<<value[start]<<" ";
    while(dir[start]!=-1)
    {
        start=dir[start];
        cout<<value[start]<<" ";

    }
    cout<<endl;
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
        mmset(dp,-1);
        mmset(dir,-1);
        value.pb(33100);
        value.pb(t);
        while(sc(a)&&a!=-1)
        {
            value.pb(a);
        }
        int len=value.size();
        // cout<<len<<endl;
        int ans=-INF,start=0;
        for(int i=1; i<len; i++)
        {
            if(dp[i]==-1)
            {
                int tmp=LIS(i,len);

                if(tmp>ans)
                {
                    ans=tmp;
                    start=i;
                }
            }
        }
        // printing_path(start);
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++tc,ans);
        value.clear();
    }
    return 0;
}
