#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define fast()          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define scll(a)         scanf("%I64d",&a)
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
#define popcount        __builtin_popcount
#define MOD             100000007
#define MX              505
int fx[]={-1,-1,0,1,1,1,0,-1};
int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);};
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);};
struct matrix{
    ll ara[5][5];
    int row,col;
};
ll mod;
matrix multi(matrix mat1,matrix mat2)
{
    matrix ans;
    ans.row=mat1.row;
    ans.col=mat2.col;

    for(int i=0;i<ans.row;i++)
    {

        for(int j=0;j<ans.col;j++)
        {
            ll sum=0;
           for(int k=0;k<mat1.row;k++)
           {
               sum+=mat1.ara[i][k]*mat2.ara[k][j];
                sum%=mod;
           }
           ans.ara[i][j]=sum;

        }
    }
    return ans;

}
matrix power(matrix mat,int p)
{
    if(p==1)return mat;
    if(p&1)
        return multi(mat,power(mat,p-1));
    else
    {
        matrix tmp=power(mat,p/2);
        return multi(tmp,tmp);
    }
}
int main()
{
            #ifdef AINAN
                       freopen("input.txt","r",stdin);
                  freopen("output.txt","w",stdout);
              #endif
            int t;
            ll a,b,n,m;
            sc(t);
            tcs(t)
            {
                scll4(a,b,n,m);
                mod=1;
                for(int i=0;i<m;i++)mod*=10;
                 a%=mod;b%=mod;

                if(n<3)
                {
                    if(n==1)Prll(b);
                    else if(n==0)Prll(a);
                    else
                        Prll((b+a)%mod);
                }
                else
                {
                    matrix xx;
                    xx.col=xx.row=2;
                    xx.ara[0][0]=xx.ara[0][1]=xx.ara[1][0]=1;
                    xx.ara[1][1]=0;
                    xx=power(xx,n-1);
                    ll tmp=xx.ara[0][0]*b+xx.ara[0][1]*a;
                     tmp%=mod;
                   Prll(tmp);

                }


            }
}
