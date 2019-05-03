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
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              101
int queens[10],values[9][9];
bool col[10],diagonal1[20],diagonal2[20];
int cnt=1;
int mx=INT_MIN;
void nqueens(int pos,int n)
{
    if(pos==n+1)
    {
         int sum=0;
        for(int i=1;i<=n;i++)
        sum+=values[i][queens[i]];
            mx=max(mx,sum);
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i]||diagonal1[i+pos]||diagonal2[n+i-pos])continue;
        queens[pos]=i;
        col[i]=diagonal1[i+pos]=diagonal2[n+i-pos]=1;
        nqueens(pos+1,n);
        col[i]=diagonal1[i+pos]=diagonal2[n+i-pos]=0;
    }
}
void CLR()
{
    mmset(queens,0);
    mmset(col,0);
    mmset(diagonal2,0);
    mmset(diagonal1,0);
    mx=INT_MIN;
}
int main()
{

      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
     int t,tc;
     sc(t);
      tcs(tc,t){
          CLR();
      for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        sc(values[i][j]);
    nqueens(1,8);
    if(mx<10)
        printf("    %d\n",mx);
    else if(mx<100)
        printf("   %d\n",mx);
    else if(mx<1000)
        printf("  %d\n",mx);
    else if(mx<10000)
        printf(" %d\n",mx);
    else
   printf("%d\n",mx);
      }
    return 0;
}


