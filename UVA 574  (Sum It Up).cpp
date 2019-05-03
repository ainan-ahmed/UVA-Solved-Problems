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
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              21
int t,n,a;
vi ans;
vi store;
map<vi,bool>solution;
void backtrack(int idx,int sum,vi ans)
{

    if(sum==t)
    {
        if(solution[ans])
            return;
        solution[ans]=1;
        int len=ans.size();
        for(int i=0;i<len;i++)
        {
            if(i>0)
                cout<<'+';
            printf("%d",ans[i]);
        }
        cout<<endl;

        return;
    }
    if(idx==n||sum>t)
        return;
    for(int i=idx;i<n;i++)
    {
       // if(sum+store[i]>t)
         //   continue;

        ans.pb(store[i]);
        backtrack(i+1,sum+store[i],ans);
        ans.pop_back();

    }
}
int main()
{

     //  freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);

    while(sc2(t,n)&&n!=0)
    {
        for(int  i=1;i<=n;i++)
        {
            sc(a);
            store.pb(a);
        }
        printf("Sums of %d:\n",t);
        backtrack(0,0,ans);
        if(solution.size()==0)
            printf("NONE\n");
        solution.clear();
        store.clear();
    }
    return 0;
}
