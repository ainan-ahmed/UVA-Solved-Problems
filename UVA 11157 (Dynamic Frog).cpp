#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define MX  100001
vi v;
int main()
{

   // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,d,t,val;
    char c;
        sc(t);
        for(int tc=1;tc<=t;tc++)
        {
            sc2(n,d);

            getchar();
            v.clear();
            v.pb(0);
            for(int i=1;i<=n;i++)
            {
                cin>>c;
                cin.ignore();
                cin>>val;

                v.pb(val);
                if(c=='B')
                    v.pb(val);
            }
            v.pb(d);

            int mx=0;
            int len=v.size();
            printf("Case %d: ",tc);
            for(int i=2;i<len;i+=2)
            {
                if(v[i]-v[i-2] > mx)
                mx= v[i]-v[i-2] ;

            }
            int mx2=0;
            for(int i=3;i<len;i+=2)
            {
                if(v[i]-v[i-2] > mx2)
                mx2= v[i]-v[i-2] ;

            }

            mx=max(mx,mx2);
            Pr(mx);

        }

    return 0;
}

