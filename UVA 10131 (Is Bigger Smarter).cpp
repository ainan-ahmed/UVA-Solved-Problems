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
#define MX              1010
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
piii ara[MX];
int I[MX];
int seq[MX];
int idx=-1;
bool cmp(piii x,piii y)
{
    if(x.second.second>y.second.second)return true;
    else if(x.second.second==y.second.second)
    {
        if(x.second.first < y.second.first)return false;
        if(x.second.first==y.second.first)return x.first<y.first;
        return true;
    }
      return false;


}
int LIS(int n)
{

    mmset(I,INF);
    I[0]=-INF;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int low=0,high=len,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid] < ara[i].second.first)
                low=mid+1;
                else
                    high=mid-1;
        }
        I[low]=ara[i].second.first;
        seq[i]=low;
        if(low >=   len){
            len=low;
            idx=i;
        }
    }
    return len;
}
void printing_path()
{
    vi ans;
    ans.pb(ara[idx].first);
    int prevI=idx;
     for(int i=idx-1;i>=0;i--)
     {

         if(ara[i].second.first<ara[prevI].second.first&&seq[i]==seq[prevI]-1)
         {
             ans.pb(ara[i].first);
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

     freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    int i=0;
    while(sc2(ara[i].second.first,ara[i].second.second)==2)
    {
         ara[i].first=i+1;
        ++i;

    }
    sort(ara,ara+i,cmp);
      //    for(int j=0;j<i;j++)
      //    cout<<ara[j].second.first<<" "<<ara[j].second.second<<" "<<ara[j].first<<endl;
    cout<<LIS(i)<<endl;

    printing_path();
    return 0;
}

