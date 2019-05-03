#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define scll(a)           scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define scll3(a,b,c)      scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX  100000

int main()
{

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
     int n,s,a,ans=n+1;
     long long sum=0;
     vector<int>v;
     while(sc2(n,s)==2)
     {
         ans=n+1;
         for(int i=0;i<n;i++)
         {
            sc(a);
            v.push_back(a);
         }
         sum=v[0];
         int low=0,high=0;
         while(high<n)
         {
             if(sum>=s)
             {
                 int tmp=high-low+1;
                    ans=min(ans,tmp);
                    if(low<high)
                    {
                        sum-=v[low];
                        low++;
                    }
                    else
                    {
                        high++,low++;
                    }
             }
             else
             {
                 high++;
                 if(high<n)sum+=v[high];
             }


         }
        if(ans==n+1)ans=0;
        Pr(ans);
        v.clear();

     }


    return 0;
}
