#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define long long       LL
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX   50001
int phi[MX],ans[MX];
void gen_phi()
{
    for(int i=1;i<MX;i++)phi[i]=i;
    phi[1]=1;
    ans[1]=1;
    for(int i=2;i<MX;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<MX;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);


            }
        }


    }
    for(int i=2;i<MX;i++)
        ans[i]=ans[i-1]+2*phi[i];

}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    gen_phi();
    int n;
    while(sc(n))
    {
        if(n==0)return 0;
        pr(ans[n]);

    }
    return 0;
}
