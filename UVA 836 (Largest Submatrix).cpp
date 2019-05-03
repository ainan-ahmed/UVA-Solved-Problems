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
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              26
int row,col;
int matrix[MX][MX];
string s[MX];
int row_sum[MX];
void  calc()
{
    int mx_sum=-INF;
    for(int left_col=0; left_col<col; left_col++)
    {
        for(int i=0; i<row; i++)
            row_sum[i]=0;
        for(int right_col=left_col; right_col<col; right_col++)
        {
            for(int i=0; i<row; i++)
            {

                row_sum[i]+=matrix[i][right_col];



            }


            int sum=0;
            for(int i=0; i<row; i++)
            {
                sum+=row_sum[i];
                if(sum<0)sum=0;
                if(sum>mx_sum)
                    mx_sum=sum;
            }

        }
    }
    Pr(mx_sum);
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc,t,n;
    sc(t);
    getchar();
    tcs(tc,t)
    {
        int i=0;

         cin>>s[0];
        int len=s[0].size();
        for(int i=1; i<len; i++)
        {
             cin>>s[i];


        }

        row=len,col=len;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(s[i][j]=='1')
                    matrix[i][j]=1;
                else
                    matrix[i][j]=-10000;

            }

        }

        //cout<<row<<" "<<col <<endl;
        calc();
        if(tc!=t)
        printf("\n");


    }
    return 0;
}

