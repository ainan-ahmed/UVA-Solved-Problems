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
#define MX              1005
//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
string s,s1;
int dp[MX][MX],len,len1;
bool visited[MX][MX];

int LCS(int i,int j)
{
    if(i==len||j==len1)return 0;
    if(visited[i][j])return dp[i][j];
    int ans=0;
    if(s[i]==s1[j])ans=1+LCS(i+1,j+1);
    else
    {
        int f1=LCS(i+1,j);
        int f2=LCS(i,j+1);
        ans=max(f1,f2);
    }
    visited[i][j]=1;
    dp[i][j]=ans;
    return dp[i][j];
}

int main()
{

       // freopen("input.txt","r",stdin);
       // freopen("output.txt","w",stdout);
        int t=0;
         while(getline(cin,s))
         {

           //  getchar();
            getline(cin,s1);
            //getchar();
             len=s.length();
             len1=s1.length();
             int ans=LCS(0,0);
              Pr(ans);

              mmset(visited,0);

         }

    return 0;
}
