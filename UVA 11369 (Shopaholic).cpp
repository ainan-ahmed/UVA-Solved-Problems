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
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define MX  100001
vector<int>v;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
     int t,a,n;
     sc(t);
     while(t--)
     {

         sc(n);
         for(int i=1;i<=n;i++){
            sc(a);
         v.pb(a);

         }
         sort(v.begin(),v.end(),comp);
         int i=0;
         ll ans=0;
         while(i<n)
         {
             if(i+2<n)
             {
                ans+=v[i+2];
                i+=3;
             }
             else
                break;

         }
         Prll(ans);
         v.clear();


     }


    return 0;
}

