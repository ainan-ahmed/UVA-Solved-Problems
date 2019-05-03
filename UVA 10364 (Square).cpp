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
#define MX              5005
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int ara[21];
 int sum,n;
bool calc(int mask,int idx,int sum2,int found)
{
    if(mask==(1<<n)-1) return true ;
    for(int i=idx;i<n;i++)
    {
        if(!check(mask,i))
        {

            if(sum2+ara[i]==sum)
            {
                if(calc(Set(mask,i),0,0,found+1))
                    return true;

            }
            if(sum2+ara[i]<sum)
            {
                if(calc(Set(mask,i),i+1,sum2+ara[i],found))
                    return true;
            }
        }
    }
    return false;
}
int main()
{

             freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
        int t;
        sc(t);
        while(t--)
        {
            sc(n);
           sum=0;
            for(int i=0;i<n;i++)
            {
                sc(ara[i]);
                sum+=ara[i];
            }
            if(sum%4!=0)
            {
                printf("no\n");
                continue;
            }
            sum/=4;
           // cout<<sum<<endl;
            if(calc(0,0,0,0))
                printf("yes\n");
            else
                printf("no\n");


        }
    return 0;
}
