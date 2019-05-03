#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX   2000001
int phi[MX],depth[MX];
void gen_phi()
{
    for(int i=1;i<MX;i++)phi[i]=i;
    phi[1]=1;
    depth[1]=0;
    for(int i=2;i<MX;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<MX;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
               // cout<<j<<"  "<<phi[j]<<endl;


            }
        }


    }

    for(int i=2;i<MX;i++)
    {
        if(phi[i]==1)
            depth[i]=1;
        else
        {
            int j=i;
            while(phi[j]!=1)
            {
                //cout<<"PHI("<<j<<")=="<<phi[j]<<endl;
                depth[i]++;
                j=phi[j];

            }
            depth[i]++;
        }
        //cout<<"Depth of"<<i<<"   "<<depth[i]<<endl;

    }


}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    gen_phi();
    int t,m,n;
    long long sum=0;
    sc(t);
    while(t--)
    {
        sc2(m,n);
        for(int i=m;i<=n;i++)
        {

            sum+=depth[i];
        }

    printf("%lld\n",sum);
    sum=0;
    }
    return 0;
}
