#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
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
bool flag[MX];
int main()
{

   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
     int n,a;
     long long ans;
     vector<int>v;
     while(sc(n)&&n!=0)
     {
         for(int i=0;i<n;i++)
         {
             sc(a);
             v.push_back(a);
         }
         long long sum=0,ans=0;
         for(int i=0;i<n;i++)
         {
             sum+=v[i];
                ans+=abs(sum);
         }
         v.clear();
         Prll(ans);
     }


    return 0;
}

