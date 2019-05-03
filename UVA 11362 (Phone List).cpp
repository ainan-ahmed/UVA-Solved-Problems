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
#define scll(a)         scanf("%lld",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
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
#define MX               10005
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
struct node{
    bool endmark;
    node *next[10];
    node()
    {
        endmark=false;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }
} *root;
bool flag;
void Insert(char *s,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int tmp=s[i]-'0';
        if(curr->endmark)flag=1;
        if(curr->next[tmp]== NULL )
        {
            curr->next[tmp]=new node();
        }
        else if(i==len-1)
        flag=1;


        curr=curr->next[tmp];

    }
    curr->endmark=1;

}
void del(node *curr)
{
    for(int i=0;i<10;i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
   delete(curr);
}
int main()
{

       //   freopen("input.txt","r",stdin);
       //   freopen("output.txt","w",stdout);
      int t,n;
      sc(t);
      tcs(t){

      root=new node();

      char s[12];
        sc(n);
        getchar();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);

            Insert(s,strlen(s));
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
            del(root);
            flag=false;

      }
    return 0;
}

