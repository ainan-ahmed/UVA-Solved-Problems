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
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX               100005
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
map<string,pii>mp;
int main()
{
           freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
       int n,m,a,tc=0;
       double cost,ans1=-INF,ans2=-INF;

       string s,s1,ans3;
       while(sc2(n,m)&&n&&m)
       {
           ans1=-INF,ans2=INF;
           if(tc!=0)
            printf("\n");
           getchar();
           for(int i=1;i<=n;i++)
            getline(cin,s);
           for(int i=1;i<=m;i++)
           {
               getline(cin,s);
                scanf("%lf %d",&cost,&a);
                 getchar();
                for(int j=1;j<=a;j++)
                    getline(cin,s1);
                    double tmp=(double)a/n;
                    if(tmp>ans1)
                    {
                        ans1=tmp;
                        ans2=cost;
                        ans3=s;
                    }
                    else if(tmp==ans1&&cost<ans2)
                    {
                        ans1=tmp;
                        ans2=cost;
                        ans3=s;
                    }

           }

           printf("RFP #%d\n%s\n",++tc,ans3.c_str());


       }
    return 0;
}
