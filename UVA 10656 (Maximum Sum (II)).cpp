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
    int n,a,l,r ;
    while(sc(n)&&n!=0)
    {
        l=0,r=0;
        for(int i=1; i<=n; i++)
        {
            sc(a);
            v.pb(a);
        }
        int i=0,j;
        bool flag=0;
        ll sum=0,mx=INT_MIN;
        while(i<n&&!flag)
        {
            j=i;
            while(j<n)
            {
                if(v[j]>=0)
                {
                    sum+=v[j];
                    j++;
                    if(j==n)
                    {
                        if(sum>mx)
                        {
                            mx=sum;
                            l=i;
                            r=j-1;
                        }
                        flag=1;
                        break;
                    }
                }

                else
                {
                    if(sum>mx)
                    {
                        mx=sum;
                        l=i;
                        r=j-1;
                    }
                    sum=0;
                    i=j+1;
                    break;
                }


            }


        }
        if(mx==0)
        {
            printf("0\n");

        }
        else{
            int y=0;
            while(v[y]==0)y++;
            printf("%d",v[y]);
        for(int i=l+y+1;i<=r;i++){
                if(v[i]!=0){
            printf(" %d",v[i]);

                }

        }
        printf("\n");
        }


        v.clear();
        sum=0;
    }
    return 0;
}

