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
#define MX              100000
vi value;
int I[MX];
int seq[MX];
int sz;
int idx=-INF;
int LIS()
{
   // reverse(ara,ara+7);
   mmset(seq,INF);
    mmset(I,INF);
    I[0]=-INF;
    int len=0;
    for(int i=0;i<sz;i++)
    {
        int low=0,high=len,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<value[i])
                low=mid+1;
                else
                    high=mid-1;
        }
        I[low]=value[i];
        seq[i]=low;

        if(low>=len){
            len=low;
            idx=i;
        }
    }
    return len;
}
void printing_path()
{
    vi ans;
    ans.pb(value[idx]);
    int prevI=idx;
     for(int i=idx-1;i>=0;i--)
     {

         if(value[i]<value[prevI]&&seq[i]==seq[prevI]-1)
         {
             ans.pb(value[i]);
             prevI=i;

         }


     }
     int len=ans.size();
     for(int i=len-1;i>=0;i--)
     {
         Pr(ans[i]);
     }

}
int main()
{

   //   freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
        int ans=0,a;
        while(sc(a)==1)
        {
            value.pb(a);

        }
        sz=value.size();
       ans= LIS();
        Pr(ans);
        printf("-\n");
         printing_path();



    return 0;
}
