#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
#define vii             vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
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
vector<int>m;
vector<int>e;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{

  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int n,d,r,a,xx;
    while(sc3(n,d,r)&&n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            sc(a);
            m.pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            sc(a);
            e.pb(a);
        }
            sort(all(m));
            sort(all(e),comp);
            ll ans=0;
            for(int i=0;i<n;i++)
            {
                xx =m[i]+e[i];
                if(xx>d)
            {
                ans+=((xx-d)*r);
            }

            }


            Prll(ans);
            m.clear();
            e.clear();

    }
    return 0;
}

