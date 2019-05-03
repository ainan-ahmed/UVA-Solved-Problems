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
#define MX  2501
vi v;
vi xx;
int t,mx,m,k,a;
bool bs(int n)
{
    int cnt=1;
    ll sum=0;
        for(int i=0;i<m;i++)
        {
            if(sum+v[i]<=n)
            {
                sum+=v[i];
            }
            else
            {
                cnt++;
                sum=v[i];
            }


        }
        return cnt<=k;
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    ll sum=0;
    sc(t);
    while(t--)
    {
        sc2(m,k);

        mx=INT_MIN,sum=0;
    for(int i=1;i<=m;i++)
    {
        sc(a);
        mx=max(mx,a);
        sum+=a;
        v.pb(a);
    }
    ll low=mx,high=sum;
    ll ans;
    while(low<high)
    {
        ll mid=(low+high)/2;
        if(bs(mid))
        {
            ans=mid;
            high=mid-1;

        }
        else
            low=mid+1;


    }
    sum=0;
   // Pr(ans);
    for(int i=m-1;i>=0;i--)
    {


        if(sum+v[i]>ans||i+1<k-xx.size())
        {
            xx.pb(sum);
            sum=v[i];

        }
        else
        {
            sum+=v[i];
        }



    }

    xx.pb(sum);
    //cout<<xx.size()<<endl;
    //for(int i=0;i<xx.size();i++)
    //    cout<<xx[i]<<" ";
    //cout<<endl;
    int index=0;

    for(int i=k-1;i>=0;i--)
    {
       // cout<<xx[i]<<endl;

        while(xx[i]>0)
        {
            if(i==0&&index==m-1)
                printf("%d",v[index]);
            else

            printf("%d ",v[index]);
            xx[i]-=v[index];
            index++;

        }
        if(i!=0)
        printf("/ ");
    }


    printf("\n");

    v.clear();
    xx.clear();

    }
    return 0;
}

