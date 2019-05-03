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
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              1005
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int main()
{

       freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
       double height,climb,fall,fatigue;
       while(scanf("%lf%lf%lf%lf",&height,&climb,&fall,&fatigue)&&height!=0)
       {

           double curr=0;
           int i=0;
          double xx=(double)(fatigue*climb)/100;

           while(++i)
           {



                    if(i!=1)
                        climb-=xx;
                     if(climb>=0)
                    curr+=climb;

                if(curr>height)
                {
                    printf("success on day %d\n",i);
                    break;
                }
                curr-=fall;
                if(curr<0)
                {
                    printf("failure on day %d\n",i);
                    break;
                }
               // cout<<curr<<" "<<climb<<endl;

           }
       }

    return 0;
}
