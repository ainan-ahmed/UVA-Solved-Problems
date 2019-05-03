#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define vii             vector<int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)           printf("%lld\n",a)
#define MX  100001
map<int,int>mp;
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
     int n,q,a;
     vector<int>v;
     int k=1;
     while(sc2(n,q))
     {
         if(n==0&&q==0)return 0;

         for(int i=0;i<n;i++)
         {
             sc(a);
             mp[a]++;
         v.push_back(a);
         }
         sort(v.begin(),v.end());
         printf("CASE# %d:\n",k++);
         for(int i=1;i<=q;i++)
         {
             sc(a);
             if(mp[a]==0)
             {
                 printf("%d not found\n",a);
                 continue;
             }
             vector<int>::iterator ans;
             ans=lower_bound(v.begin(),v.end(),a);
             printf("%d found at %d\n",a,ans-v.begin()+1);
         }
         v.clear();
         mp.clear();

     }

    return 0;
}

