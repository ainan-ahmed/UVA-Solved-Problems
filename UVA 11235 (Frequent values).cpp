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
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define SZ              size()
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX               100005
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
int ara[MX],n;
int tree[MX*3];
int l[MX],r[MX];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=1;
        return ;
    }
    int mid=(b+e)>>1;
    int left=(node<<1);
    int right=(node<<1) +1;
    init(left,b,mid);
    init(right,mid+1,e);
    int f1,f2;
    if(ara[mid]==ara[mid+1])
    {
        if(mid-b+1 >l[mid])f1=l[mid];
        else
            f1=l[mid]-l[b]+1;
        if(e-mid>r[mid+1])f2=r[mid+1];
        else
            f2=r[mid+1]-r[e]+1;
         tree[node]=max(max(tree[left],tree[right]),f1+f2);
    }
    else
        tree[node]=max(tree[left],tree[right]);

}
int query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)return -1;
    if(b>=i&&e<=j)
        return  tree[node];
    int left=(node<<1);
    int right=(node<<1) +1;
    int mid=(b+e)>>1;
    int f1=query(left,b,mid,i,j),f3,f4;
    int f2=query(right,mid+1,e,i,j);
    if(f1==-1)return f2;
    else if(f2==-1)return f1;
     if(ara[mid]==ara[mid+1])
     {
        if(mid-max(b,i)+1 >l[mid])f3=l[mid];
        else
            f3=l[mid]-l[max(b,i)]+1;
        if(min(e,j)-mid>r[mid+1])f4=r[mid+1];
        else
            f4=r[mid+1]-r[min(e,j)]+1;
         return max(max(f1,f2),f3+f4);
     }
     else
        return max(f1,f2);
}
int main()
{
        //    freopen("input.txt","r",stdin);
      //     freopen("output.txt","w",stdout);
             int t,q,b,e,choice,add;
             while(sc(n)&&n)
             {
                 sc(q);
                 for(int i=1;i<=n;i++){
                    sc(ara[i]);
                    if(i>1&&ara[i-1]==ara[i])
                        l[i]=l[i-1]+1;
                        else
                            l[i]=1;
                 }
                 for(int i=n;i>=1;i--)
                 {
                     if(i==n||ara[i]!=ara[i+1])r[i]=1;
                     else
                        r[i]=r[i+1]+1;
                 }
                    init(1,1,n);
                  //  printf("Case %d:\n",tc);
                 for(int i=1;i<=q;i++)
                 {
                     sc2(b,e);
                     Pr(query(1,1,n,b,e));
                 }
             }
    return 0;
}

