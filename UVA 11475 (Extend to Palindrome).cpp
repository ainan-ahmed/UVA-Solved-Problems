#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<pii,int>
#define vi              vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
#define mmset(a,val)    memset(a,val,sizeof(a))
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define SZ              size()
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define hash_val        347
#define MOD             1000000007
#define MX              100006
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
char text[MX],pattern[MX];
int p[MX],j;
void prefix( char * ss)
{
    int len=strlen(ss);
    j=0;
    for(int i=1;i<len;i++)
    {
        while(j>0&& ss[j]!=ss[i])
            j=p[j-1];
        if(ss[i]==ss[j])++j;
        p[i]=j;
    }
}
void kmp()
{
    int len=strlen(text);
    int len2=strlen(pattern);
    prefix(pattern);
    j=0;
    for(int i=0;i<len;i++)
    {
        while(j>0 &&text[i]!=pattern[j])
            j=p[j-1];
        if(text[i]==pattern[j])++j;
    }
}
int main()
{
           //             freopen("input.txt","r",stdin);
           //  freopen("output.txt","w",stdout);

             while(scanf("%s",text) !=EOF)
             {
                 int len=strlen(text);
                for(int i=0,j=len-1;j>=0;i++,j--)
                    pattern[i]=text[j];
                  //  cout<<text<<" "<<pattern<<endl;
                kmp();
                printf("%s",text);
                for(int i=j;i<len;i++)
                    printf("%c",pattern[i]);
            printf("\n");
             }


        return 0;
}
