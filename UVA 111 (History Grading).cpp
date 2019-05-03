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
#define sc5(a,b,c,d,e)    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
 #define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              1125
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int I[22];
int ara[22],ara2[22];
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
            if(I[mid]<ara2[i])
                low=mid+1;
                else
                    high=mid-1;
        }
        I[low]=ara2[i];
        if(low>len)
            len=low;
    }
    return len;
}
int main()
{

           freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
          int a,n;
            sc(n);
            for(int i=0;i<n;i++)
            {
                sc(ara[i]);
            }
            while(sc(a)==1)
            {
                ara2[a-1]=ara[0];

                for(int i=1;i<n;i++)
                {
                    sc(a);
                    ara2[a-1]=ara[i];
                }
               // for(int i=0;i<n;i++)
                //     cout<<ara2[i]<<" ";
               // cout<<endl;
                cout<<LIS(n)<<endl;
            }




    return 0;
}
