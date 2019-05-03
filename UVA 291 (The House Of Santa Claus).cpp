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
#define MX              21
int edges[6][6],cnt=1;
vi ans;
void backtrack(int prev)
{
    if(ans.size()==9)
    {
        for(int i=0;i<9;i++)
        {
            printf("%d",ans[i]);
            //if(i!=8)printf(" ");
        }
        printf("\n" );
        return;
    }
    for(int i=1;i<=5;i++)
    {
        if(prev==0&&i!=1)return;
        if(prev==0||edges[prev][i]==1)
        {
            if(prev!=0){
            edges[prev][i]=0;
            edges[i][prev]=0;
            }
            ans.pb(i);

            backtrack(i);
            if(prev!=0){
            edges[prev][i]=1;
            edges[i][prev]=1;
            }
            ans.pop_back();
        }
    }

}

int main()
{

    //   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    edges[1][2]=1;
    edges[1][3]=1;
    edges[1][5]=1;
    edges[2][1]=1;
    edges[2][3]=1;
    edges[2][5]=1;
    edges[3][1]=1;
    edges[3][2]=1;
    edges[3][4]=1;
    edges[3][5]=1;
    edges[4][3]=1;
    edges[4][5]=1;
    edges[5][1]=1;
    edges[5][2]=1;
    edges[5][3]=1;
    edges[5][4]=1;

    backtrack(0);
    return 0;
}
