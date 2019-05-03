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
 
int main()
{

    freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,t,xx,tc=1;
    sc(t);
    string s;

    while(t--)
    {
        sc(n);
        cin>>s;
        xx=0;
        int i=0;
       while(i<n)
        {
            if(s[i]=='.')
            {
                xx++;
                i+=3;
            }
            else
                i++;
        }
        printf("Case %d: %d\n",tc++,xx);

    }
    return 0;
}

