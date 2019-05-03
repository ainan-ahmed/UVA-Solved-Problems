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
vector<int>dragon;
vector<int>knight;
bool used[20001];
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
      int n,m,a;

      while(sc2(n,m)&&n!=0&&m!=0)
      {
        for(int i=1;i<=n;i++)
        {
            sc(a);
            dragon.pb(a);
        }
        for(int i=1;i<=m;i++)
        {
            sc(a);
            knight.pb(a);
        }
        sort(dragon.begin(),dragon.end());
        sort(knight.begin(),knight.end());
        bool flag=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            flag=0;
            for(int j=0;j<m;j++)
            {
                if(dragon[i]<=knight[j]&&!used[j])
                {
                    used[j]=1;
                    flag=1;
                    ans+=knight[j];
                    break;
                }
            }
            if(!flag)
            {
                printf("Loowater is doomed!\n");
                break;
            }



        }
        if(flag)
            Prll(ans);
        dragon.clear();
        knight.clear();
        mmset(used,0);

      }
    return 0;
}

